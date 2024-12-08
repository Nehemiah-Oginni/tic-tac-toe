const EMPTY = ' '
const SIZE = 3
function bestMove() 
{
    //AI makes its turn

    const id = e.target.id

    let available = [];

    for (let i = 0; i < SIZE; i++) 
    {
        for (let j = 0; j < SIZE; j++) 
        {
            if (boxes[i][j] == '') //checks that spot is available
            {
                available.push({i,j});
            }
        }
    }

    let move = random(available);
    board[move.i][move.j] = AI;
    currentPlayer = human;



}
    /* for (let i = 0; i < SIZE; i++) 
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
}  */