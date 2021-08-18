import "dart:io";

main(List<String> args) {
  int k = int.parse(stdin.readLineSync());
  String s = stdin.readLineSync();

  if(k < s.length) {
    print(s.substring(0, k) + "...");
  }
  else {
    print(s);
  }
}
