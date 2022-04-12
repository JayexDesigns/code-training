import 'dart:io';
import 'dart:math';

String readLineSync() {
  String? s = stdin.readLineSync();
  return s == null ? '' : s;
}

void main() {
  int L = int.parse(readLineSync());
  int H = int.parse(readLineSync());
  String T = readLineSync();
  const List letters = [
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    '?'
  ];
  String text = '';
  for (int i = 0; i < H; i++) {
    String ROW = readLineSync();
    for (int j = 0; j < T.length; ++j) {
      int char;
      try {
        char = letters.indexOf(T[j].toLowerCase()) * L;
        text += ROW.substring(char, char + L);
      } catch (e) {
        char = letters.indexOf('?') * L;
        text += ROW.substring(char, char + L);
      }
    }
    text += "\n";
  }

  print(text);
}
