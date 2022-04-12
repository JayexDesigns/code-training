import 'dart:io';
import 'dart:math';

String readLineSync() {
  String? s = stdin.readLineSync();
  return s == null ? '' : s;
}

void main() {
  List inputs;
  inputs = readLineSync().split(' ');
  int W = int.parse(inputs[0]);
  int H = int.parse(inputs[1]);
  int N = int.parse(readLineSync());
  inputs = readLineSync().split(' ');
  int X0 = int.parse(inputs[0]);
  int Y0 = int.parse(inputs[1]);

  List<int> possibleWidth = [for (var i = 0; i < W; ++i) i];
  List<int> possibleHeight = [for (var i = 0; i < H; ++i) i];
  int currentPosX = X0;
  int currentPosY = Y0;

  while (true) {
    String bombDir = readLineSync();

    if (bombDir.contains("L")) {
      possibleWidth =
          possibleWidth.sublist(0, possibleWidth.indexOf(currentPosX));
      currentPosX = possibleWidth[(possibleWidth.length / 2).floor()];
    } else if (bombDir.contains("R")) {
      possibleWidth =
          possibleWidth.sublist(possibleWidth.indexOf(currentPosX) + 1);
      currentPosX = possibleWidth[(possibleWidth.length / 2).floor()];
    }

    if (bombDir.contains("U")) {
      possibleHeight =
          possibleHeight.sublist(0, possibleHeight.indexOf(currentPosY));
      currentPosY = possibleHeight[(possibleHeight.length / 2).floor()];
    } else if (bombDir.contains("D")) {
      possibleHeight =
          possibleHeight.sublist(possibleHeight.indexOf(currentPosY) + 1);
      currentPosY = possibleHeight[(possibleHeight.length / 2).floor()];
    }

    print('$currentPosX $currentPosY');
  }
}
