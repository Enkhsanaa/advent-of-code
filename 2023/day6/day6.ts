const input = await Deno.readTextFile('./day6_input.txt')
const parts = input.split('\r\n')

let times = parts[0]
    .split(':')[1]
    .split(' ')
    .filter((s) => s)
    .map((s) => Number.parseFloat(s))
let distances = parts[1]
    .split(':')[1]
    .split(' ')
    .filter((s) => s)
    .map((s) => Number.parseFloat(s))
console.log(times, distances)

let answer = 1
for (let i = 0; i < times.length; i++) {
    let count = 0
    for (let j = 1; j <= times[i]; j++) {
        if ((times[i] - j) * j >= distances[i]) {
            count++
        }
    }
    answer *= count
}

console.log('Part 1:', answer)

times = [Number.parseFloat(times.map((n) => String(n)).join(''))]
distances = [Number.parseFloat(distances.map((n) => String(n)).join(''))]
answer = 1
for (let i = 0; i < times.length; i++) {
    let count = 0
    for (let j = 1; j <= times[i]; j++) {
        if ((times[i] - j) * j >= distances[i]) {
            count++
        }
    }
    answer *= count
}

console.log('Part 2:', answer)
