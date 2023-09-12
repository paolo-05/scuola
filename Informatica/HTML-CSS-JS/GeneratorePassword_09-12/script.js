const slider = document.getElementById('password-length');
slider.addEventListener("input", function(){
    const sliderValue = slider.value;
    const displayValue = document.getElementById('password-length-value');
    displayValue.textContent = sliderValue;
});

const button = document.getElementById('generate-button');
button.addEventListener("click", function(){
    const lowerChecked = document.getElementById('lower-case').checked;
    const upperChecked = document.getElementById('upper-case').checked;
    const numbersChecked = document.getElementById('numbers').checked;
    const symbolsChecked = document.getElementById('symbols').checked;

    let typesEnabled = [];

    if(!lowerChecked && !upperChecked && !numbersChecked && !symbolsChecked){
        alert("Seleziona un'opzione!");
        return;
    }
    if(lowerChecked){
        typesEnabled.push("lower");
    }
    if(upperChecked){
        typesEnabled.push("upper");
    }
    if(numbersChecked){
        typesEnabled.push("numbers");
    }
    if(symbolsChecked){
        typesEnabled.push("symbols");
    }

    const length = document.getElementById('password-length').value;
    let password = "";

    for (let i = 0; i < length; i++) {
        randomType = typesEnabled[Math.floor(Math.random() * typesEnabled.length)];
        switch (randomType) {
            case "lower":
                password += lowerChar();
                break;
            case "upper":
                password += upperChar();
                break;
            case "numbers":
                password += numberChar();
                break;
            default:
                password += symbolChar();
                break;
        }
    }

    passwordDisplay = document.getElementById('password-display');
    passwordDisplay.textContent = password;
});

function upperChar(){
    const uppercaseLetters = Array.from({ length: 26 }, (_, index) => String.fromCharCode(65 + index));
    const randomIndex = Math.floor(Math.random() * uppercaseLetters.length);
    const randomElement = uppercaseLetters[randomIndex];
    return randomElement;
}

function lowerChar(){
    const lowercaseLetters = Array.from({ length: 26 }, (_, index) => String.fromCharCode(97 + index));
    const randomIndex = Math.floor(Math.random() * lowercaseLetters.length);
    const randomElement = lowercaseLetters[randomIndex];
    return randomElement;
}

function numberChar(){
    const randomElement = Math.floor(Math.random() * 10);
    return randomElement;
}

function symbolChar(){
    const symbols = ['!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '{', '}', '[', ']', '|', '\\', ';', ':', '"', "'", '<', '>', ',', '.', '?', '/', '~', '`'];
    const randomIndex = Math.floor(Math.random() * symbols.length);
    const randomElement = symbols[randomIndex];
    return randomElement;
}
