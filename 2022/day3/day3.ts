const input = await Deno.readTextFile("./day3_input.txt");
const rucksacks = input.split("\r\n");

function charToScore(char: string) {
  const charCode = char.charCodeAt(0);
  if ("a".charCodeAt(0) <= charCode && charCode <= "z".charCodeAt(0)) {
    return charCode - "a".charCodeAt(0) + 1;
  }
  if ("A".charCodeAt(0) <= charCode && charCode <= "Z".charCodeAt(0)) {
    return charCode - "A".charCodeAt(0) + 27;
  }
  return 0;
}

let part1Answer = 0;
for (const rucksack of rucksacks) {
  const items = rucksack.split("");
  const compartmentA = items.slice(0, items.length / 2);
  const compartmentB = items.slice(items.length / 2, items.length);

  const set = new Set();
  compartmentA.forEach((item) => set.add(item));
  const sharedItems = compartmentB.filter((item) => set.has(item));
  part1Answer += charToScore(sharedItems[0]);
}

console.log("Part 1. Answer: ", part1Answer);

let part2Answer = 0;
let elfCount = 0;
let group: { [key: string]: number } = {};
for (const rucksack of rucksacks) {
  const items = new Set(rucksack.split(""));
  for (const item of items) {
    if (group[item] >= 1) {
      group[item]++;
    } else {
      group[item] = 1;
    }
  }
  elfCount++;
  if (elfCount % 3 === 0) {
    part2Answer += charToScore(
      Object.keys(group).reduce((ans, letter) => {
        return group[letter] >= 3 ? letter : ans;
      }, " ")
    );
    group = {};
  }
}

console.log("Part 2. Answer: ", part2Answer);
