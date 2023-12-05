const text = await Deno.readTextFile("./day1_input.txt");
const elves = text.split("\r\n\r\n");
const caloriesByEachElf = elves
  .map((elf) =>
    elf
      .split("\r\n")
      .map((food) => Number.parseInt(food))
      .reduce((acc, cur) => acc + cur, 0)
  )
  // Sort in DEC order
  .sort((a, b) => (a < b ? 1 : -1));

// Part 1: Who has most calories?
const part1Answer = caloriesByEachElf.reduce(
  (curMax, cur) => Math.max(curMax, cur),
  0
);
console.log("Part 1: Who has most calories? Answer: ", part1Answer);

// Part 2: Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?
const part2Answer = caloriesByEachElf
  .slice(0, 3)
  .reduce((acc, cur) => acc + cur, 0);
console.log(
  "Part 2: How many Calories are those Elves carrying in total? Answer: ",
  part2Answer
);
