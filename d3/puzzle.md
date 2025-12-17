# Day 3: Lobby

You descend a short staircase, enter the surprisingly vast lobby, and are quickly cleared by the security checkpoint. When you get to the main elevators, however, you discover that each one has a red light above it: they’re all offline.

> “Sorry about that,” an Elf apologizes as she tinkers with a nearby control panel.  
> “Some kind of electrical surge seems to have fried them. I’ll try to get them online soon.”

You explain your need to get further underground.

> “Well, you could at least take the escalator down to the printing department, not that you’d get much further than that without the elevators working. That is, you *could* if the escalator weren’t also offline.”

> “But don’t worry! It’s not fried; it just needs power. Maybe you can get it running while I keep working on the elevators.”



## Batteries

There are batteries nearby that can supply emergency power to the escalator for just such an occasion.  
Each battery is labeled with its **joltage rating**, a value from **1 to 9**. You make a note of their ratings (your puzzle input). For example:

```
987654321111111
811111111111119
234234234234278
818181911112111
```

The batteries are arranged into **banks**:

- Each line corresponds to one bank.
- Within each bank, you must turn on **exactly two batteries**.
- The bank’s joltage is the **two-digit number formed by those batteries**, in order.
- Batteries **cannot be rearranged**.

**Example:**  
For a bank `12345`, turning on batteries `2` and `4` produces **24 jolts**.


## Maximum Joltage per Bank

For the example input above:

- **98**7654321111111 → maximum joltage is **98** (first two batteries)
- **8**1111111111111**9** → maximum joltage is **89**
- 2342342342342**78** → maximum joltage is **78** (last two batteries)
- 818181**9**1111**2**111 → maximum joltage is **92**


## Total Output Joltage

The total output joltage is the **sum of the maximum joltage from each bank**:

```
98 + 89 + 78 + 92 = 357
```

## Task

There are many batteries in front of you.

**Find the maximum joltage possible from each bank.  
What is the total output joltage?**

## Part Two

The escalator doesn’t move. The Elf explains that it probably needs more joltage to overcome the static friction of the system and hits the big red **“joltage limit safety override”** button. You lose count of the number of times she needs to confirm *“yes, I’m sure”* and decorate the lobby a bit while you wait.

Now, you need to make the **largest joltage** by turning on **exactly twelve batteries** within each bank.

The joltage output for a bank is still the number formed by the digits of the batteries you’ve turned on. The only difference is that the output now consists of **12 digits instead of two**.


## Example (Revisited)

```
987654321111111
811111111111119
234234234234278
818181911112111
```

The resulting joltages are much larger:

- **987654321111** → produced by turning on everything except some trailing `1`s  
- **811111111119** → produced by turning on everything except some `1`s  
- **434234234278** → produced by skipping a `2`, a `3`, and another `2` near the start  
- **888911112111** → produced by turning on everything except some `1`s near the front  



## Total Output Joltage

The total output joltage is the sum of the maximum joltage from each bank:

```
987654321111

* 811111111119
* 434234234278
* 888911112111
  = 3121910778619
```



## Task

What is the **new total output joltage**?

