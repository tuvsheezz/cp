function main(input) {
  'use strict';
  const [N, H, W] = input.trim().split('\n').map(n => parseInt(n, 10));

  let ans = (N - H + 1) * (N - W + 1)
  console.log(ans);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

