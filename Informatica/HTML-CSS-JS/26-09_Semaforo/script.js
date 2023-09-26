semaforo = document.querySelectorAll('div.semaforo');

document.addEventListener('DOMContentLoaded', () => {
    passaRosso();
});
function passaVerde()
{
    semaforo[0].style.backgroundColor = 'gray';
    semaforo[2].style.backgroundColor = 'green';
    setTimeout(passaGiallo, 4000);
}
 
function passaGiallo()
{
    semaforo[2].style.backgroundColor = 'gray';
    semaforo[1].style.backgroundColor = 'yellow';
    setTimeout(passaRosso, 2000);
}
 
function passaRosso()
{
    semaforo[1].style.backgroundColor = 'gray'
    semaforo[0].style.backgroundColor = 'red';
    setTimeout(passaVerde, 5000);
}