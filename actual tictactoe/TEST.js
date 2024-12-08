const SIZE = 3;
const EMPTY = ' ';
const PLAYER = 'X';
const AI = 'O';

let gameboard = Array(SIZE).fill(null).map(() => Array(SIZE).fill(EMPTY));
let currentPlayer = PLAYER;

// Initialize DOM Elements
const boxes = document.querySelectorAll('.box');
const playerText = document.getElementById('playerText');
const restartBtn = document.getElementById('restartBtn');

// Event Listeners
restartBtn.addEventListener('click', restartGame);
boxes.forEach((box) => box.addEventListener('click', playerMove));

// Initialize Gameboard
function initializeMap() {
    for (let i = 0; i < SIZE; i++) {
        for (let j = 0; j < SIZE; j++) {
            gameboard[i][j] = EMPTY;
        }
    }
    renderBoard();
}

// Render the Board
function renderBoard() {
    boxes.forEach((box, index) => {
        const row = Math.floor(index / SIZE);
        const col = index % SIZE;
        box.textContent = gameboard[row][col];
    });
}

// Player Move
function playerMove(event) {
    const boxId = event.target.id;
    const row = Math.floor(boxId / SIZE);
    const col = boxId % SIZE;

    if (gameboard[row][col] === EMPTY) {
        gameboard[row][col] = PLAYER;
        renderBoard();
        if (checkWin(gameboard, PLAYER)) {
            playerText.textContent = "Player Wins!";
            endGame();
            return;
        }
        if (checkTie(gameboard)) {
            playerText.textContent = "It's a Tie!";
            endGame();
            return;
        }
        aiSelect();
    }
}

// AI Move
function aiSelect() {
    // AI tries to win
    for (let i = 0; i < SIZE; i++) {
        for (let j = 0; j < SIZE; j++) {
            if (gameboard[i][j] === EMPTY) {
                gameboard[i][j] = AI;
                if (checkWin(gameboard, AI)) {
                    renderBoard();
                    playerText.textContent = "AI Wins!";
                    endGame();
                    return;
                }
                gameboard[i][j] = EMPTY;
            }
        }
    }

    // AI tries to block
    for (let i = 0; i < SIZE; i++) {
        for (let j = 0; j < SIZE; j++) {
            if (gameboard[i][j] === EMPTY) {
                gameboard[i][j] = PLAYER;
                if (checkWin(gameboard, PLAYER)) {
                    gameboard[i][j] = AI;
                    renderBoard();
                    return;
                }
                gameboard[i][j] = EMPTY;
            }
        }
    }

    // AI makes a random move
    while (true) {
        const randomRow = Math.floor(Math.random() * SIZE);
        const randomCol = Math.floor(Math.random() * SIZE);
        if (gameboard[randomRow][randomCol] === EMPTY) {
            gameboard[randomRow][randomCol] = AI;
            renderBoard();
            break;
        }
    }

    if (checkWin(gameboard, AI)) {
        playerText.textContent = "AI Wins!";
        endGame();
        return;
    }
    if (checkTie(gameboard)) {
        playerText.textContent = "It's a Tie!";
        endGame();
    }
}

// Check for Win
function checkWin(board, player) {
    // Check rows, columns, and diagonals
    for (let i = 0; i < SIZE; i++) {
        if (
            board[i][0] === player &&
            board[i][1] === player &&
            board[i][2] === player
        ) {
            return true;
        }
        if (
            board[0][i] === player &&
            board[1][i] === player &&
            board[2][i] === player
        ) {
            return true;
        }
    }
    if (
        board[0][0] === player &&
        board[1][1] === player &&
        board[2][2] === player
    ) {
        return true;
    }
    if (
        board[0][2] === player &&
        board[1][1] === player &&
        board[2][0] === player
    ) {
        return true;
    }
    return false;
}

// Check for Tie
function checkTie(board) {
    return board.flat().every((cell) => cell !== EMPTY);
}

// Restart the Game
function restartGame() {
    initializeMap();
    currentPlayer = PLAYER;
    playerText.textContent = "Nene's Tic Tac Toe";
}

// End the Game
function endGame() {
    boxes.forEach((box) => box.removeEventListener('click', playerMove));
}

// Start the Game
initializeMap();