import "dart:io";

main(List<String> args) {
  String s = stdin.readLineSync();
  print('2'.allMatches(s).length);
}
