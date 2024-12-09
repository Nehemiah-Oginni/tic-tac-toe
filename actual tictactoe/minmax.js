const EMPTY = ' '
const SIZE = 3
function bestMove() 
{
    //AI makes its turn

    const id = e.target.id

    let available = [];

    let bestScore = -Infinity;

    for (let i = 0; i < SIZE; i++) 
    {
        for (let j = 0; j < SIZE; j++) 
        {
            if (board[i][j] == '') //checks that spot is available
            {
                board[i][j] = AI;
                let score = minimax(board) 
                board[i][j] = '';
                if(score > bestScore) 
                {
                    bestScore = score;
                    move = {i, j};
                }
            }
        }
    }
    board[move.i][move.j] = AI;
    currentPlayer = human;
}

function minimax(board)
{
    return 1;
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