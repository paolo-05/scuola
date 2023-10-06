const description = document.getElementById('desc');
const qt = document.getElementById('qt');
const select = document.getElementById('select');

const addButton = document.getElementById('add');
const resetButton = document.getElementById('reset');

const list = document.getElementById('list');
const totSpan = document.getElementById('saldo');
let tot = 0;

addButton.addEventListener('click', () => {   
    if(qt.value == ''){
        alert("Inserisci un importo valido");
        return;
    }
    if(description.value == ''){
        alert("Inserisci una descrizione valida");
        return;
    }
    list.innerHTML += `${description.value}: ${select.value} ${Number(qt.value)} Euro <br>`;
    
    if(select.value === '+')
    {
        tot += Number(qt.value);
    }
    else {
        tot -= Number(qt.value);
    }
    
    totSpan.textContent = ""+tot;
});

resetButton.addEventListener('click', () => {
    qt.value = '';
    description.value = '';
    list.textContent = '';
    saldo.textContent = '';
});