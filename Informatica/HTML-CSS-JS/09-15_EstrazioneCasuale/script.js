const slider = document.getElementById('generating');
const minValue = document.getElementById('min-value');
const maxValue = document.getElementById('max-value');
const displayValue = document.getElementById('generating-value');
const repetionCheckBox = document.getElementById('repetition');

document.addEventListener('DOMContentLoaded', function () {
    const savedSliderValue = localStorage.getItem('generating');
    if (savedSliderValue !== null) {
        slider.value = savedSliderValue;
        displayValue.value = savedSliderValue;
    }

    const savedMinValue = localStorage.getItem('min-value');
    minValue.value = savedMinValue;

    const savedMaxValue = localStorage.getItem('max-value');
    maxValue.value = savedMaxValue;

    const savedRepetion = localStorage.getItem('repetitionChecked') === 'true';
    repetionCheckBox.checked = savedRepetion;
})

slider.addEventListener("input", function () {
    let sliderValue = slider.value;
    if(repetionCheckBox.checked){
        if(sliderValue >= maxValue.value - minValue.value + 1) {
            sliderValue = maxValue.value - minValue.value + 1;
        }
    }
    displayValue.value = sliderValue;
    localStorage.setItem('generating', sliderValue);
});

repetionCheckBox.addEventListener("change", function () {
    localStorage.setItem(repetionCheckBox.id + 'Checked',repetionCheckBox.checked);
});

minValue.addEventListener("input", function () {
    localStorage.setItem("min-value", minValue.value);
})

maxValue.addEventListener("input", function () {
    localStorage.setItem("max-value", maxValue.value);
})


// Function to generate a random integer between min and max (inclusive)
function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

// Function to generate random numbers with repetition
function generateWithRepetition(count, min, max) {
    const numbers = [];
    for (let i = 0; i < count; i++) {
        numbers.push(getRandomInt(min, max));
    }
    return numbers;
}

// Function to generate random numbers without repetition
function generateWithoutRepetition(count, min, max) {
    if (count > max - min + 1) {
        // Cannot generate unique numbers if count is greater than the range
        alert("Impossibile generare numeri non ripetuti: numeri da estrarre maggiore dell'intervallo.")
        return [];
    }

    const numbers = new Set();
    while (numbers.size < count) {
        const randomNumber = getRandomInt(min, max);
        numbers.add(randomNumber);
    }
    return Array.from(numbers);
}

// Event listener for the "Estrai" button
document.getElementById('generate-button').addEventListener('click', function () {
    const count = parseInt(displayValue.value);
    const min = parseInt(minValue.value);
    const max = parseInt(maxValue.value);
    const repetition = repetionCheckBox.checked;

    if(min > max){
        alert("Il valore minore non può essere maggiore del massimo!!");
        return;
    }

    if(minValue.value === '' || maxValue.value === ''){
        alert("Il valore non può essere nullo");
        return;
    }


    let generatedNumbers = [];
    if (!repetition) {
        generatedNumbers = generateWithRepetition(count, min, max);
    } else {
        generatedNumbers = generateWithoutRepetition(count, min, max);
    }

    const numbersDisplay = document.getElementById('numbers-display');
    numbersDisplay.textContent = generatedNumbers.join(', ');
});