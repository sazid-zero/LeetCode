function createHelloWorld() {
    return Function.prototype.bind.call(() => "Hello World");
}