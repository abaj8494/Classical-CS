// rest operator
const sum = (function() {
    return function sum(...args) {
        return args.reduce((a,b) => a + b, 0);
    }
})();

console.log(sum(1,2,3,4));

// guard operator
const message = 5 && 'hello';
console.log(message)

// destructuring
let todo = {'name': 'Aayush Bajaj', 'dueDate': 'yesterday'}
const { name, dueDate } = todo;
/*
equivalent to:
    const name = todo.name;
    const dueDate = todo.dueDate;
*/
