const enemyHands = " ABC"; // Rock, Paper, Scissors
const myHands = " XYZ";

const scores = {
  won: 6,
  tie: 3,
  loss: 0,
};

function mod(hand: number) {
  return ((hand + 2) % 3) + 1;
}

const input = await Deno.readTextFile("./day2_input.txt");
const rounds = input.split("\r\n");

const part1TotalScore = rounds.reduce((score, round) => {
  const [enemy, me] = round.split(" ");
  let roundScore = myHands.indexOf(me);
  if (mod(enemyHands.indexOf(enemy) - 1) === myHands.indexOf(me)) {
    roundScore += scores.loss;
  }
  if (enemyHands.indexOf(enemy) === myHands.indexOf(me)) {
    roundScore += scores.tie;
  }
  if (mod(enemyHands.indexOf(enemy) + 1) === myHands.indexOf(me)) {
    roundScore += scores.won;
  }
  return score + roundScore;
}, 0);

console.log("Part 1: Answer: ", part1TotalScore);

const part2TotalScore = rounds.reduce((score, round) => {
  const [enemy, me] = round.split(" ");
  let roundScore = 0;
  if (me === "X") {
    // Lose
    roundScore += scores.loss;
    roundScore += mod(enemyHands.indexOf(enemy) - 1);
  }
  if (me === "Y") {
    // Draw
    roundScore += scores.tie;
    roundScore += mod(enemyHands.indexOf(enemy));
  }
  if (me === "Z") {
    // Win
    roundScore += scores.won;
    roundScore += mod(enemyHands.indexOf(enemy) + 1);
  }
  return score + roundScore;
}, 0);
console.log("Part 2: Answer: ", part2TotalScore);
