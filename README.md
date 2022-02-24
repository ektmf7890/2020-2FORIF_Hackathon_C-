# 2020-2FORIF_Hackathon_C-
2020-2 포리프 해커톤 알뚝깨 씨쁠쁠 '같이여행가듀오'

Members from the Algorithm Mentoring group undertook a project for the 2020 Winter Forif Hackathon related to the [Stable Roommate Problem](https://en.wikipedia.org/wiki/Stable_roommates_problem).
We will be implementing Irving's algorithm and assigning partners for each of the Forif members. We distributed a survey among the Forif members before the Hacackthon, asking their
travelling perferences, such as whether they enjoy historical sites or nature more. According to these perfernce data, we will be assigning travelling partners in an algorithmic way that
ensures the outcome will lead to biggest overall satisfaction. 

## Stable Roommate Problem
The stable roommate problem is that of mathing two groups of n people, both of whom has ranked the members of the opposite group in perfernce, so that no unmatched couple perfers
each other over their current partner.

<img src='https://user-images.githubusercontent.com/58558382/155460586-602f2709-9245-4ced-8630-b98b7f73d7f5.png' height=150> <img src='https://user-images.githubusercontent.com/58558382/155460872-d6598b5a-1732-4fd9-a265-7f9ecd6f866a.png' height=150>

For exmample, if John and Peter, Sam and Paul are matched couples, but John perfers Sam over Peter, and Sam also perfers Johm over Paul, this is not a stable match.

## Irving's Algorithm 
Irving's algorithm [[1]](#1) was proposed by Irving in 1984 as a way to solve this problem. The algorithm is consisted of three phases.

### First Phase
<pre>
(1) Person x proposes to y   
   (1-1) If y holds no proposal that is from someone they prefe more than x, they hold x's proposal.   
   (1-2) Otherwise, he rejects it.   
(2) x continues proposing according to the order appearing in his/her perference list, until somebody holds the proposal.
</pre>
 
 <img src='https://user-images.githubusercontent.com/58558382/155463414-b8cc5098-0798-423d-91db-604cb713a256.png' height=200>

Above is a perference list of 6 people, where the goal is to make 3 couples in a stable match. 
Charlie proposed to Peter, Peter to Kelly, and Elise to Peter. Peter rejects Charlie's proposal since Elise is higher in his perfence list, according to step 1-2 of the algorithm.

<img src='https://user-images.githubusercontent.com/58558382/155463781-cea184b2-4e44-4c50-9402-986356d9efe9.png' height=200>

So Charlie's proposal to Peter will become invalid, and he will have to propose again to the person on the top of his perfernce list which would be Paul. 
If we keep perform the step several times, we will end up with a reduced perference table looking like this.

<img src='https://user-images.githubusercontent.com/58558382/155464262-ab2ac9a9-414a-4155-83ce-7574951d88b7.png' height=200>

### Second Phase
Now everyone holds a unique proposal, so in phase 2 we remove entries from the perference lists that are less prefered than the person's proposed parter.
For example, Paul holds a proposal from Charlie, so everyone in Paul's list that is less prefered than Charlie(Sam, Peter, Kelly) will be removed.
We do this for everyone and as long as the reuslting table has no empty list, we can find a stable match. 

<img src='https://user-images.githubusercontent.com/58558382/155464763-aa5e0e4f-1bac-422a-a6c4-948d2a0da379.png' height=200>

### Third Phase
Finally, we check the lists still containing more than one person and find existing cycles. We make two sets of people p and q, where p<sub>0</sub> is the first person in the table with more
than one person in their list. In our case p<sub>0</sub> is Charlie since he has Paul and Sam in his list.

We then fill out the table of p and q according to the rules shown below. If someone is repeted in p, that means we have a found a cycle and we eliminate it by making q<sub>i</sub> reject
the proposal from p<sub>i+1<sub>. 

<img src='https://user-images.githubusercontent.com/58558382/155465575-9c634088-dfdb-47d2-827d-e02831a3f425.png' height=200>
  
 Here, Charlie is repeated in p, indicating a cycle has been found, so Pual(q<sub>1</sub>) rejects his offer from Charlie(p<sub>2</sub>) and Sam(q<sub>0</sub>) rejects her offer from Elise(p<sub>1</sub>).
 Now we have our stable match! In some cases, phase three has to be repeated several times for a stable match to be found.
 
<img src='https://user-images.githubusercontent.com/58558382/155465973-a3e27a81-4f79-4ef2-8141-5075554ee2d0.png' height=200>

## Hackathon Result
We implemented Irving's algorithm [here](https://github.com/ektmf7890/2020-2FORIF_Hackathon_C-/blob/master/final.cpp) in C++ 
and applied it to our own perfernce list we made through survey data. 
This allowed us to come up with a stable match of travelling partners which we presented in the Forif Winter Hackathon.
  
<img src='https://user-images.githubusercontent.com/58558382/155466532-1ce77743-9c3d-4944-8a3f-e8ad613207c6.png' height=500>


## References
<a id='1'>[1]</a>
Irving, R.W. (1984). *An Efficient Algorithm for the “Stable Roommates” Problem*. https://uvacs2102.github.io/docs/roomates.pdf
