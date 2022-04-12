const n = parseInt(readline());
var inputs = readline().split(' ');
var lowest;
for (let i = 0; i < n; i++) {
    const t = parseInt(inputs[i]);
    if (lowest == null || Math.abs(t) < Math.abs(lowest)) {
        lowest = t;
    }
    else if (Math.abs(t) == Math.abs(lowest)) {
        if (lowest < 0) {
            lowest = t;
        }
    }
}

console.log((lowest == undefined) ? 0 : lowest);
