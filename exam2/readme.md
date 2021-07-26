# CS172 Exam 2 (Summer 2021) -- due 24 hours after you begin the exam

You are allowed to look at any of your previous programming solutions or the video sessions for the exam. You may also look at http://www.cplusplus.com/reference/string/string/ or http://www.cplusplus.com/reference/vector/vector. 

Since this is an online course, we need to work on the honor system. You must put the following statement at the top of any source files you write:

`I affirm that all code given below was written solely by me, <give your name>, and that any help I received adhered to the rules stated for this exam.`

Additionally, since this is a time-limited exam, please log your start time and end time. The time limit is 24 hours.

Please save your solution to GitHub, and email Pete the URL for the project. Also email Pete the UML class diagram for your class definitions.

## Project Requirements

The Lilac Bloomsday run is one of the largest runs in the nation. It is a 7.46 mile run that winds through and around downtown Spokane. It attracts people from all over the world to compete, and generally up to 30,000 people will start the race. With that many people, Bloomsday has to be very careful about lining people up. If a person who plans to walk most of the race is on the front line with people who plan to run at a 6 minute-per-mile pace, you will have a lot of real problems. So to solve that, Bloomsday assigns a color to each racer based on their planned pace. Your job is to read a file of registered runners, along with their pace, sort those runners by their planned pace, and write that information into files for each color.
You’ll need a Runner class, as follows:

| Runner |
| ------ |
-firstName: string
-lastName: string
-pace: int
| ------ |
+getFirstName(): string
+getLastName(): string
+getPace(): int

Your program will read from a file (attached) where each line is a runner. Each line will have the format:

`first_name last_name pace`

There will be no spaces in the first_name or last_name fields, and the pace will be in total seconds per mile (so a 6:30 pace/mile would be indicated as 450 seconds). Once the file is read and stored in a vector, you need to sort the vector in ascending order based on the runner’s pace, so that the fastest pace is the first runner in the vector.

Once sorted, you are to write the runners to files based on this table:

| Minimum pace/mile | Maximum pace/mile | filename |
| ----------------- | ----------------- | -------- | 
| 0 seconds | 360 seconds | `white.txt` |
| 361 seconds | 420 seconds | `yellow.txt` |
| 421 seconds | 480 seconds | `green.txt` |
| 481 seconds | 540 seconds | `orange.txt` |
| 541 seconds | 600 seconds | `blue.txt` |
| 601 seconds | 720 seconds | `lilac.txt` |
| 721 seconds | 1200 seconds | `red.txt` |

Finally, you need to create a file called summary.txt. In that file you need to output the total number of runners, and the number of runners in each color group. Now, assume each runner takes one second to get started. The fastest group (white) will go first at 9:00am, but we can’t let yellow start until 60 seconds after all of the white group crosses the starting line. For example, if there are 200 runners in the white group, it will take 200 seconds to get everyone across the starting line, so the yellow group can’t start until 200+60 seconds after 9:30 (9:04:20). Your summary.txt file should also state when each group should start the race.

Implement also a test program in main() to ensure the files are created correctly.

| Rubric: |   |
| ------- | - |
| Runner class | 10 points |
| read from file | 15 points |
| sort vector | 15 points |
| write runner files | 10 points |
| write summary file | 10 points |
| code compiles | 25 points |
| readable, commented code | 15 points |

