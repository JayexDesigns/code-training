const MESSAGE = readline();

var BINARY = '';
for (i of MESSAGE) {
    let char = i.charCodeAt().toString(2);
    while (char.length < 7) {
        char = `0${char}`;
    }
    BINARY += char;
}

var encodedMessage = '';
var last = null;
for (i of BINARY) {
    if (last == i) {
        encodedMessage += "0";
    }
    else {
        if (last != null) {
            encodedMessage += " ";
        }
        if (i == "1") {
            encodedMessage += "0 0";
        }
        else {
            encodedMessage += "00 0";
        }
        last = i;
    }
}

console.error(MESSAGE);
console.error(BINARY);
console.log(encodedMessage);
