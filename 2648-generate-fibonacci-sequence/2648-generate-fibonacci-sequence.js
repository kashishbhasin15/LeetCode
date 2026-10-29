/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {

    var a=0;
    var b=1;
    
    while (true)
    {
        yield a;
        var next=a+b;
        a=b;
        b=next;
    }

};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */