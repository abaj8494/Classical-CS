function PCEINDEX(pce, pceNum) {
    return (pce * 10 + pceNum);
}

let gameBoard = {};

gameBoard.pieces = new Array(BRD_SQ_NUM);
gameBoard.side = COLOURS.white;
gameBoard.fiftyMove = 0;
gameBoard.hisPly = 0;
gameBoard.ply = 0;
gameBoard.enPas = 0;
gameBoard.castlePerm = 0; // something about bits

gameBoard.material = new Array(2);

// we shouldn't check moves for all the empty squares
// so we finesse with data structures:
gameBoard.pceNum = new Array(13);
gameBoard.pList = new Array(14 * 10);
gameBoard.posKey = 0;

gameBoard.moveList = new Array(MAXDEPTH * MAXPOSITIONMOVES);
gameBoard.moveScores = new Array(MAXDEPTH * MAXPOSITIONMOVES);
gameBoard.moveListStart = new Array(MAXDEPTH);

function printBoard() {

    let sq, file, rank, piece;

    console.log("\nGame Board:\n");
    for (rank = RANKS.RANK_8; rank >= RANKS.RANK_1; rank--) {
        let line = (rankChar[rank] + "  ");
        for (file = FILES.FILE_A; file <= FILES.FILE_H; file++) {
            sq = FR2SQ(file, rank);
            piece = gameBoard.pieces[sq];
            line += (" " + pceChar[piece] + " ");
        }
        console.log(line);
    }

    console.log("");
    let line = "   ";
    for (file = FILES.FILE_A; file <= FILES.FILE_H; file++) {
        line += (' ' + fileChar[file] + ' ');
    }

    console.log(line);
    console.log("side: " + sideChar[gameBoard.side]);
    console.log("enPas: " + gameBoard.enPas);
    line = "";

    if(gameBoard.castlePerm & CASTLEBIT.WKCA) line += 'K';
    if(gameBoard.castlePerm & CASTLEBIT.WQCA) line += 'Q';
    if(gameBoard.castlePerm & CASTLEBIT.BKCA) line += 'k';
    if(gameBoard.castlePerm & CASTLEBIT.BQCA) line += 'q';

    console.log("castle: " + line);
    console.log("key: " + gameBoard.posKey.toString(16)); //hexadecimal
}

function generatePosKey() {
    let finalKey = 0;
    let piece = PIECES.EMPTY;

    for (let sq = 0; sq < BRD_SQ_NUM; ++sq) {
        piece = gameBoard.pieces[sq];
        if(piece != PIECES.EMPTY && piece != SQUARES.OFFBOARD) {
            finalKey ^= PieceKeys[(piece * 120) + sq];
        }
    }

    if (gameBoard.side === COLOURS.WHITE) {
        finalKey ^= sideKey;
    }

    if (gameBoard.enPas != SQUARES.NO_SQ) {
        finalKey ^= PieceKeys[gameBoard.enPas];
    }

    finalKey ^= CastleKeys[gameBoard.castlePerm];
    return finalKey;
}


function printPieceLists() {
    let piece, pceNum;

    for(piece = PIECES.wP; piece <= PIECES.bK; ++piece) {
        for(pceNum = 0; pceNum < gameBoard.pceNum[piece]; ++pceNum) {
            console.log('piece ' + pceChar[piece] + ' on ' + prSq(gameBoard.pList[PCEINDEX(piece,pceNum)]));

        }
    }
}

function updateListsMaterial() {
    let piece, sq, colour;


    for (let i = 0; i < 14 * 120; ++i) { // think the length might need to be 14 * 10.
        gameBoard.pList[i] = PIECES.EMPTY;
    }

    for (let i = 0; i < 2; ++i) {
        gameBoard.material[i] = 0;
    }

    for (let i = 0; i < 13; ++i) {
        gameBoard.pceNum[i] = 0;
    }

    for (let i = 0; i < 64; ++i) {
        sq = SQ120(i);
        piece = gameBoard.pieces[sq];
        if (piece != PIECES.EMPTY) {
            colour = PieceCol[piece];
            gameBoard.material[colour] += PieceVal[piece];
            gameBoard.pList[PCEINDEX(piece, gameBoard.pceNum[piece])] = sq;
            gameBoard.pceNum[piece]++;
        }
        
    }
    printPieceLists();
}

function resetBoard() {
    for (let i = 0; i < BRD_SQ_NUM; ++i) {
        gameBoard.pieces[i] = SQUARES.OFFBOARD;
    }

    for (let i = 0; i < 64; ++i) {
        gameBoard.pieces[SQ120(i)] = PIECES.EMPTY;
    }
    gameBoard.side = COLOURS.BOTH;
    gameBoard.enPas = SQUARES.NO_SQ;
    gameBoard.fiftyMove = 0;
    gameBoard.ply = 0;
    gameBoard.hisPly = 0;
    gameBoard.castlePerm = 0;
    gameBoard.posKey = 0;
    gameBoard.moveListStart[gameBoard.ply] = 0;
}

function parseFen(fen) {
    resetBoard();

    let rank = RANKS.RANK_8;
    let file = FILES.FILE_A;
    let piece = 0;
    let count = 0;
    let i = 0;
    let sq120 = 0;
    let fenCnt = 0;

    while ((rank >= RANKS.RANK_1) && fenCnt < fen.length) {
        count = 1;
        switch(fen[fenCnt]) {
            case 'p': piece = PIECES.bP; break;
            case 'r': piece = PIECES.bR; break;
            case 'n': piece = PIECES.bN; break;
            case 'b': piece = PIECES.bB; break;
            case 'k': piece = PIECES.bK; break;
            case 'q': piece = PIECES.bQ; break;
            case 'P': piece = PIECES.wP; break;
            case 'R': piece = PIECES.wR; break;
            case 'N': piece = PIECES.wN; break;
            case 'B': piece = PIECES.wB; break;
            case 'K': piece = PIECES.wK; break;
            case 'Q': piece = PIECES.wQ; break;

            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                piece = PIECES.EMPTY;
                count = fen[fenCnt].charCodeAt() - '0'.charCodeAt();
                break;
            case '/':
            case ' ':
                rank--;
                file = FILES.FILE_A;
                fenCnt++;
                continue;
            default:
                console.log("FEN parsing error\n");
                return;
        }
        for (i = 0; i < count; i++) {
            sq120 = FR2SQ(file,rank);
            gameBoard.pieces[sq120] = piece;
            file++;
        }
        fenCnt++;

    }

    gameBoard.side = (fen[fenCnt] == 'w') ? COLOURS.WHITE : COLOURS.BLACK;

    fenCnt += 2;
    for(i = 0; i < 4; i++) {
        if(fen[fenCnt] == ' ') {
            break;
        }

        switch(fen[fenCnt]) {
            case 'K': gameBoard.castlePerm |= CASTLEBIT.WKCA; break;
            case 'Q': gameBoard.castlePerm |= CASTLEBIT.WQCA; break;
            case 'k': gameBoard.castlePerm |= CASTLEBIT.BKCA; break;
            case 'q': gameBoard.castlePerm |= CASTLEBIT.BQCA; break;
            default:                                          break;

        }
        fenCnt++;
    }
    fenCnt++;

    if (fen[fenCnt] != '-') {
        file = fen[fenCnt].charCodeAt() - 'a'.charCodeAt();
        rank = fen[fenCnt + 1].charCodeAt() - '1'.charCodeAt();
        console.log("fen[fenCnt]: " + fen[fenCnt] + " File: " + file + " Rank: " + rank);
        gameBoard.enPas = FR2SQ(file,rank);
    }

    gameBoard.posKey = generatePosKey();


    updateListsMaterial();
    sqAttacked(21, 0);
    printSqAttacked();
}

function printSqAttacked() {
    let sq, file, rank, piece; 

    console.log("\nAttacked: \n");

    for (rank = RANKS.RANK_8; rank >= RANKS.RANK_1; rank--) {
        let line = ((rank + 1) + " ");
        for (file = FILES.FILE_A; file <= FILES.FILE_H; file++) {
            sq = FR2SQ(file, rank);
            piece = sqAttacked(sq, gameBoard.side) ? "X" : "-";
            line += (" " + piece + " ");
        }
        console.log(line);
    }
    console.log("");
}


function sqAttacked(sq, side) {
    let pce, t_sq;

    // checks pawn attacks
    if (side == COLOURS.WHITE) {
        if (gameBoard.pieces[sq - 11] == PIECES.wP || gameBoard.pieces[sq - 9] == PIECES.wP ) {
            return true;
        }
    } else {
            if (gameBoard.pieces[sq + 11] == PIECES.bP || gameBoard.pieces[sq + 9] == PIECES.bP ) {
                return true;
            }
    }
    
    for (let i = 0; i < 8; i++) { // knight checks
        pce = gameBoard.pieces[sq + KnDir[i]];
        if (pce != SQUARES.OFFBOARD && PieceCol[pce] == side && PieceKnight[pce] == true) {
            return true;
        }
    }

    for (let i = 0; i < 4; ++i) { // rook checks
        dir = RkDir[i];
        t_sq = sq + dir;
        pce = gameBoard.pieces[t_sq];
        while(pce != SQUARES.OFFBOARD) {
            if (pce != PIECES.EMPTY) {
                if (PieceRookQueen[pce] == true && PieceCol[pce] == side) {
                    return true;
                }
                break;
            }
            t_sq += dir;
            pce = gameBoard.pieces[t_sq];
        }
    }

    for (let i = 0; i < 4; ++i) { // bishop
        dir = BiDir[i];
        t_sq = sq + dir;
        pce = gameBoard.pieces[t_sq];
        while(pce != SQUARES.OFFBOARD) {
            if (pce != PIECES.EMPTY) {
                if (PieceBishopQueen[pce] == true && PieceCol[pce] == side) {
                    return true;
                }
                break;
            }
            t_sq += dir;
            pce = gameBoard.pieces[t_sq];
        }
    }

    for (let i = 0; i < 8; i++) { // king
        pce = gameBoard.pieces[sq + KiDir[i]];
        if (pce != SQUARES.OFFBOARD && PieceCol[pce] == side && PieceKing[pce] == true) {
            return true;
        }
    }

    return false;
}
