JUSTIN VENTURA COSC320-002

README in .txt becuase my old readme was deleted and github has no history for markdown files because its worthless.
EXTRA CREDIT ATTEMPTED AS PART OF QUESTION F!


A) I used the code we went over in lecture and also the code from previous labs for the sorts.  
This did not take much planning.

B) HIRE ASSISTANT: Best case O(1hire), worst: O(n hires) for n candidates.  
Each sort had an average case of O(nlogn), but quick and rand quick had a worst case of O(n^2), 
with rand quick being slightly better.  In general, merge and heapsort were pretty fast and 
were not affected much by the inputs, but quick and rand quick were sensitive to the ordering 
and did not do well with arrays that were close to pre/backward sorted arrays.

C) Hire assistant was sort of logarithmic in growth, and was nowhere near its worst case.  
The four sorts were relatively close to O(nlogn) except for quick sort which was closer to O(n^2). 
The Hire-assistant and rand quick sort both ended up performing better than the expected performance 
proved in class, especially the Hire-Assistant based on my data.

D) The worst case swaps for the Hire-Assistant is O(n) where n is the number of candidates, and this 
worst case was NEVER even close to being reached from my data.  This is simply because the chances of
the array being shuffled in a completely random order is highly unlikely compared to the chances of
the best candidate being put near the beginning since everyone after the best candidate won't matter.

E) See Attached.

F) EXTRA CREDIT ATTEMPTED: In order to judge randomness I had to come up with some sort of metric, 
but based on these metrics all I could do was make a simple guess.  I decided to test how many 
elements were still in their original indices after being shuffled.  While these metrics did show
some kind of result, I figured in order to be truly random, each possible permutation should be
equally likely.  This is one of the definitions of being uniformly random, and testing for any
elements being in the same index really doesn't help solve the problem while using this definition.
It did however show differences between the two swap functions.  I noticed that with the shuffle
function, it made the Hire-Assistant perform better on average than the random-swaps function. This
is most likely due to the fact that since the range of possible priorities in the shuffle function 
is significantly higher than the range of possible swaps in the random-swaps function, the shuffle
could potentially perform better in "randomness" on average. This was not always true, but based on
the average performance in my data, the more "random" function was the shuffle function.

G) Most of the code is reused from old labs (the sorts) and the Hire-Assistant is from lecture, so 
honestly more efficiency is unlikely considering the fact that most of these algorithms depended on
many "random" factors.  For example, rand quick sort performed better than quick sort on AVERAGE, and
most of the algorithm's worst cases were kind of avoided due to the randomness created in the arrays
beforehand.
