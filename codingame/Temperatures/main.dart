import 'dart:io';

String readLineSync() {
  String? s = stdin.readLineSync();
  return s == null ? '' : s;
}

void main() {
  List inputs;
  int n = int.parse(readLineSync());
  inputs = readLineSync().split(' ');
  int? lowest = null;
  for (int i = 0; i < n; i++) {
    int t = int.parse(inputs[i]);
    if (lowest == null || lowest.abs() > t.abs()) {
      lowest = t;
    }
    else if (lowest.abs() == t.abs()) {
      if (lowest < 0) {
        lowest = t;
      }
    }
  }

  if (lowest == null) {
    lowest = 0;
  }

  print(lowest);
}