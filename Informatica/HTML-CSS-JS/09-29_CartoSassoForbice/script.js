const hardModeCheckBox = document.getElementById('hard-mode');
const computerChoiceImg = document.getElementById('computer-choice');
const computerChoice = document.getElementById('computer-choice-card');
const computerChoiceText = document.getElementById('computer-choice-text');

const gamesWonSpan = document.getElementById('games-won');
const gamesLostSpan = document.getElementById('games-lost');
const gamesTiedSpan = document.getElementById('games-tied');

let gamesWon = 0;
let gamesLost = 0;
let gamesTied = 0;

const choices = ['rock', 'paper', 'scissors'];
const choicesIT = ['Sasso', 'Carta', 'Forbici'];

const playerChoices = document.querySelectorAll('div.card#player');
for (let i = 0; i < playerChoices.length; i++) {
    playerChoices[i].addEventListener('click', () => {
        var computerChoice;
        if (hardModeCheckBox.checked) {
            computerChoice = hardMode(i);
        } else {
            computerChoice = normalMode();
        }
        computerChoiceImg.src = `./img/${choices[computerChoice]}.png`;
        computerChoiceText.textContent = choicesIT[computerChoice];

        const result = checkWin(i, computerChoice);
        updateGameStats(result);

        highlightChoices(i, computerChoice, result);
    });
}

function normalMode() {
    const randomNum = Math.floor(Math.random() * 3);
    return randomNum;
}

function hardMode(choice) {
    var num;
    if (choice == 0) {
        num = 1;
    }
    if (choice == 1) {
        num = 2;
    }
    if (choice == 2) {
        num = 0;
    }
    return num;
}

function checkWin(player, computer) {
    var win = true;
    var tie = false;

    if (player == 0 && computer == 1) {
        win = false;
        gamesLost++;
    } else if (player == 1 && computer == 2) {
        win = false;
        gamesLost++;
    } else if (player == 2 && computer == 0) {
        win = false;
        gamesLost++;
    } else if (player == computer) {
        win = false;
        tie = true;
        gamesTied++;
    } else {
        gamesWon++;
        win = true;
    }

    // window.alert(win ? "Hai vinto!" : tie ? "Pareggio" : "Hai perso");
    return win;
}

function updateGameStats(result) {
    if (result) {
        gamesWonSpan.textContent = gamesWon;
    } else {
        gamesLostSpan.textContent = gamesLost;
        if (!result) gamesTiedSpan.textContent = gamesTied;
    }
}

function highlightChoices(player, computer, result) {
    playerChoices.forEach((choice) => {
        choice.classList.remove('choice-win', 'choice-lose');
    });
    computerChoice.classList.remove('choice-win', 'choice-lose');

    if (result) {
        playerChoices[player].classList.add('choice-win');
    } else {
        playerChoices[player].classList.add('choice-lose');
    }

    if (!result) {
        computerChoice.classList.add('choice-win');
    } else {
        computerChoice.classList.add('choice-lose');
    }
}