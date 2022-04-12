import 'dart:io';
import 'dart:math';

String readLineSync() {
  String? s = stdin.readLineSync();
  return s == null ? '' : s;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void main() {
    String MESSAGE = readLineSync();

    String BINARY = '';
    MESSAGE.codeUnits.map((int strInt) {
      String bin = strInt.toRadixString(2); 
      while (bin.length < 7) {
        bin = '0$bin';
      }
      BINARY += bin;
    }).toList();

    String encodedMessage = '';
    String? last = null;
    for (int i = 0; i < BINARY.length; ++i) {
      if (last == BINARY[i]) {
          encodedMessage += "0";
      }
      else {
          if (last != null) {
              encodedMessage += " ";
          }
          if (BINARY[i] == "1") {
              encodedMessage += "0 0";
          }
          else {
              encodedMessage += "00 0";
          }
          last = BINARY[i];
      }
    }

    print(encodedMessage);
}