const input = await Deno.readTextFile("./day4_input.txt");
const pairs = input.split("\r\n");

let part1Answer = 0;
for (const pair of pairs) {
  const [elf1, elf2] = pair.split(",");
  const [l1, r1] = elf1.split("-").map((_) => Number.parseInt(_));
  const [l2, r2] = elf2.split("-").map((_) => Number.parseInt(_));
  if (l1 <= l2 && r2 <= r1) {
    part1Answer++;
  } else if (l2 <= l1 && r1 <= r2) {
    part1Answer++;
  }
}

console.log("Part 1", part1Answer);

let part2Answer = 0;
for (const pair of pairs) {
  const [elf1, elf2] = pair.split(",");
  const [l1, r1] = elf1.split("-").map((_) => Number.parseInt(_));
  const [l2, r2] = elf2.split("-").map((_) => Number.parseInt(_));
  if (r1 >= l2 && l1 <= r2) {
    part2Answer++;
  } else if (l1 <= r2 && r1 >= r2) {
    part2Answer++;
  }
}

console.log("Part 2", part2Answer);
