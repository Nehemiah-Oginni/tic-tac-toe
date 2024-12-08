let playerText = document.getElementById('playerText')
let restartBtn = document.getElementById('restartBtn')
let boxes = Array.from(document.getElementsByClassName('box'))
let SIZE = 3

let winnerIndicator = getComputedStyle(document.body).getPropertyValue('--winning-blocks')
let boardColorReset = getComputedStyle(document.body).getPropertyValue('--original-color')

const AI = "O"
const X_MARK = "X"
let currentPlayer = X_MARK
let spaces = Array(9).fill(null)

const startGame = () => {
    boxes.forEach(box => box.addEventListener('click', boxClicked))
}

function boxClicked(e)// after each click the AI will place its mark
{
    const id = e.target.id

    if(!spaces[id])
    {
        spaces[id] = currentPlayer
        e.target.innerText = currentPlayer

        if(playerHasWon() !==false)
        {
            playerText.innerText = `${currentPlayer} has won!`
            let winning_blocks = playerHasWon()

            

            winning_blocks.forEach(block => {
                boxes[block].style.backgroundColor = winnerIndicator;
            });

            return
        }
        //currentPlayer = currentPlayer == X_MARK ? O_MARK : X_MARK
        aiMove()
    }
}

/* function aiMove() 
{
    const id = e.target.id

    for (let i = 0; i < SIZE; i++) 
    {
        for (let j = 0; j < SIZE; j++) 
        {
            if (boxes[i][j] === null) 
            {
                e.target.innerText = AI;
                if (playerHasWon(AI)) return;
                e.target.innerText = '';
            }
        }
    }
    for (let i = 0; i < SIZE; i++) 
    {
        for (let j = 0; j < SIZE; j++) 
        {
            if (boxes[i][j] === null) 
            {
                e.target.innerText = AI;
                return;
            }
        }
    }
} */
    function aiMove()
{
    const emptySpaces = spaces.reduce((acc, space, index) => {
        if (space === null) acc.push(index);
        return acc;
    }, []);
    
    if (emptySpaces.length > 0) {
        // Choose a random empty space
        const randomIndex = emptySpaces[Math.floor(Math.random() * emptySpaces.length)];
        
        spaces[randomIndex] = AI;
        boxes[randomIndex].innerText = AI;

        if(playerHasWon() !==false)
        {
            playerText.innerText = `${AI} has won!`
            let winning_blocks = playerHasWon()

            winning_blocks.forEach(block => {
                boxes[block].style.backgroundColor = winnerIndicator;
            });
        }
    }
}

const winningCombos =
[
    // Rows
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],

    // Columns
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],

    // Diagonals
    [0, 4, 8],
    [2, 4, 6]
]
function playerHasWon()
{
    for (const condition of winningCombos) //grabs all 3 numbers and makes sure they are the same mark
    {
        let [a, b, c] = condition

        if(spaces[a] && spaces[a] == spaces[b] && spaces[a] == spaces[c])
        {
            return [a, b,c]
        }
    }
    return false
}
restartBtn.addEventListener('click', restart)

function restart()//resets the gameboard
{
    spaces.fill(null)

    boxes.forEach
    (
        box => {box.innerText = ''
        box.style.backgroundColor = '';}
    )

    

    playerText.innerText = 'NENEs AI TIC TAC TOE'

    currentPlayer = X_MARK
}

startGame()