var inputs = readline().split(' ');
const W = parseInt(inputs[0]);
const H = parseInt(inputs[1]);
const N = parseInt(readline());
var inputs = readline().split(' ');
const X0 = parseInt(inputs[0]);
const Y0 = parseInt(inputs[1]);

var possibleWidth = [...Array(W).keys()];
var possibleHeight = [...Array(H).keys()];
var currentPosX = X0;
var currentPosY = Y0;

while (true) {
    const bombDir = readline();

    if (bombDir.includes("L")) {
        possibleWidth = possibleWidth.slice(0, possibleWidth.indexOf(currentPosX));
        currentPosX = possibleWidth[Math.floor(possibleWidth.length/2)];
    }
    else if (bombDir.includes("R")) {
        possibleWidth = possibleWidth.slice(possibleWidth.indexOf(currentPosX)+1);
        currentPosX = possibleWidth[Math.floor(possibleWidth.length/2)];
    }

    if (bombDir.includes("U")) {
        possibleHeight = possibleHeight.slice(0, possibleHeight.indexOf(currentPosY));
        currentPosY = possibleHeight[Math.floor(possibleHeight.length/2)];
    }
    else if (bombDir.includes("D")) {
        possibleHeight = possibleHeight.slice(possibleHeight.indexOf(currentPosY)+1);
        currentPosY = possibleHeight[Math.floor(possibleHeight.length/2)];
    }

    console.log(`${currentPosX} ${currentPosY}`);
}
