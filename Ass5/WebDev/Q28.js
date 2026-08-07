function* fibonacci() {
    let a = 0;
    let b = 1;
    let c = a + b;
    
    while(true) {
        yield a;
        c = a + b;
        a = b;
        b = c;
    }
    
}

// Input:
const fibGen = fibonacci();

console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);

// Output:
// 0
// 1
// 1
// 2
// 3
// 5