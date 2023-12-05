const input = await Deno.readTextFile('./day5_input.txt')
const parts = input.split('\n\n')

const seeds = parts[0]
    .substring(7)
    .split(' ')
    .map((_) => Number.parseInt(_.trim()))

const steps: number[][][] = []
for (let i = 0; i < 7; i++) {
    const stepData = parts[i + 1].split('\n')
    if (stepData.length > 1) {
        stepData.shift()
        steps.push(
            stepData.map((_) =>
                _.split(' ').map((__) => Number.parseInt(__.trim()))
            )
        )
    }
}

function getLocation(location: number) {
    for (const step of steps) {
        for (const s of step) {
            if (s[1] <= location && location < s[1] + s[2]) {
                location = s[0] + location - s[1]
                break
            }
        }
    }
    return location
}

let minLocation = 100000000000
for (const seed of seeds) {
    minLocation = Math.min(minLocation, getLocation(seed))
}

console.log(`Part 1: ${minLocation}`)

const seedRanges = []
for (let i = 0; i < seeds.length; i += 2) {
    seedRanges.push([seeds[i], seeds[i + 1]])
}

minLocation = 100000000000
await Promise.all(
    seedRanges.map(
        (range) =>
            new Promise((resolve) => {
                for (let seed = range[0]; seed < range[0] + range[1]; seed++) {
                    minLocation = Math.min(minLocation, getLocation(seed))
                }
                resolve(0)
            })
    )
)

console.log(`Part 2: ${minLocation}`)
