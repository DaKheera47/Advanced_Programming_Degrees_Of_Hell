# Notes

# CSpace

-   type
-   name

# Types of Spaces

# CAssessment -> CSpace

## Attributes

-   motivationalCost
-   achievement
-   yearOfStudy
-   type = 1

## Rules

-   can be completed only if player who lands has enough motivation
-   achievement is added to player's success
-   motivationalCost is subtracted from player's levelOfMotivation
-   if already completed by player, nothing happens
-   `<Player> completes <assessment> for <cost> and achieves <score>`
-   if completed by another player, motivational cost and achievement is divided between the two player. print: `<Player> helps and achieves <score>`

# CBogus & CBonus → CSpace

## What happens

-   spinner is spun again
-   action taken according to table
-   print message:

```markdown
<Player> lands on Bonus
Win a hackathon. Gain motivation of 50
<Player> has <current motivation>
```

# CAccusedOfPlagiarism -> CSpace

type = 7

## What happens

-   their piece moves to CPlagiarismHearing
-   motivation reduced by 50
-   print message: `<Player> lands on Accused of Plagiarism and goes to the hearing' '<Player> loses motivation`

# CSkipClass -> CSpace

type = 8

## What happens

-   nothing special
-   print message: `<Player> lands on Skip Classes and hangs out with their dodgy mates`

# CExtraCurricular -> CSpace

type = 3

## What happens

-   rules are same as CAssessment
-   motivation granted is 100

## Edgecases:

-   **Landing on already completed ExtraCurricular**
    Motivational cost is divided between the two players.
    the other player also gets full motivation, and half achievement (which goes into success)
    `<Player> motivates <receiving player> by joining their activity`

# CWelcomeWeek → CSpace

## **What happens**

-   the player’s motivation is increased by 250.
-   The players year incremented.
    -   Check if player has completed 3 of the current year’s assessments BEFORE incrementing
    -   If a player completes year 3, game ends immediately. print a congratulations message: `<Player> has graduated, and hence has won the game. Congratulations.`
-   You must output the message:
    `<Player> attends Welcome Week and starts year <year> more motivated!`

# CPlayer

## Attributes

-   name
-   levelOfMotivation (can be negative) = 1000
-   success (can't be negative) = 0
-   yearOfStudy = 1
-   currentPosition
-   assessmentsCompleted -> CAssessment

# CSpinner

spin() -> random number 1 - 10

# Program behaviour

-   use vectors for storing things
-   use typedef and/or using keyword for cleaning up

### **When the game is started:**

a welcome message is displayed. The format of the message is:
`Welcome to Scumbag College`

### **For each turn:**

the player’s name and the number they spin is displayed. Output the message: `<Player> spins <number>`

On the next line the name of the player and the name of the space that the player landed on are displayed. `<Player> lands on <space name>`

### **At the start of each round:**

the round number should be output: `round <round number>`

### upon game over:

`Game Over. <Player1> has achieved <success> <Player2> has achieved <success> <Player> wins.`

### every player turn:

`<Player>’s motivation is <motivation> and success is <success>`
