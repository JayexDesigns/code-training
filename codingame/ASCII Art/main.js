const L = parseInt(readline());
const H = parseInt(readline());
const T = readline();
const letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '?'];
var text = '';
for (let i = 0; i < H; i++) {
    const ROW = readline();
    for (let j = 0; j < T.length; ++j) {
        const index = letters.indexOf(T[j].toLowerCase())*L;
        text += ROW.substr(index, L);
    }
    text += "\n";
}

console.log(text);
