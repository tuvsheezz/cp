import "dart:io";

main(List<String> args) {
  List<int> s = stdin
      .readLineSync()
      .toString()
      .split(' ')
      .map((e) => int.parse(e))
      .toList();

  int r = 0;

  for (int i = 0; i < s[0]; i++) {
    List<int> c = stdin
        .readLineSync()
        .toString()
        .split(' ')
        .map((e) => int.parse(e))
        .toList();
    if (s[1] <= c[0] && s[2] <= c[1]) {
      r++;
    }
  }

  print(r);
}
