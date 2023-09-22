const selected = document.getElementById('drop-down');
const image = document.getElementById('image');
const city = document.getElementById('city');
const description = document.getElementById('description');

const images = [
    './img/milano.jpg',
    './img/roma.jpg',
    './img/torino.jpg',
    './img/firenze.jpg',
    './img/venezia.jpg'
];
const descriptions = [
    "Milano è un comune italiano di 1361908 abitanti, capoluogo della regione Lombardia e dell'omonima città metropolitana, è centro di una delle più popolose aree metropolitane d'Europa, è inoltre il secondo comune più popoloso d'Italia (dopo Roma) e rientra tra le venti città più grandi dell'Europa intera. Fondata intorno al 590 a.C. da una tribù celtica facente parte del gruppo degli Insubri e appartenente alla cultura di Golasecca, fu conquistata dagli antichi Romani nel 222 a.C. Con il passare dei secoli, Mediolanum accrebbe la sua importanza sino a divenire capitale dell'Impero romano d'Occidente; in questo periodo fu promulgato l'editto di Milano, che concesse a tutti i cittadini, quindi anche ai cristiani, la libertà di culto.",
    "Roma è la capitale d'Italia. Inoltre è capoluogo dell'omonima città metropolitana e della regione Lazio. Il comune di Roma è dotato di un ordinamento amministrativo speciale, denominato Roma Capitale e disciplinato dalla legge dello Stato. Contando 2746639 abitanti, è il comune più popoloso d'Italia e il terzo dell'Unione europea dopo Berlino e Madrid, mentre, con una superficie di 1287,36 km2, è il comune più esteso d'Italia e dell'Unione europea, nonché la quinta città più estesa d'Europa dopo Mosca, Istanbul, Londra e San Pietroburgo. È inoltre il comune europeo con la maggiore superficie di aree verdi. Secondo la tradizione, Roma sarebbe stata fondata il 21 aprile 753 a.C. da Romolo (sebbene scavi recenti presso il Lapis niger farebbero risalire la fondazione a due secoli prima); nel corso dei suoi tre millenni di storia, è stata la prima metropoli dell'Occidente, cuore pulsante di una delle più importanti civiltà antiche, che influenzò la società, la cultura, la lingua, la letteratura, l'arte, l'architettura, l'urbanistica, l'ingegneria civile, la filosofia, la religione, il diritto e i costumi dei secoli successivi. Luogo di origine della lingua latina, fu capitale dell'antico Stato romano, che estendeva il suo dominio su tutto il bacino del Mediterraneo e gran parte dell'Europa; poi dello Stato Pontificio, sottoposto al potere temporale dei papi; quindi del Regno d'Italia dal 1871 al 1946, poi della Repubblica Italiana. Per antonomasia è definita l'Urbe, Caput mundi e Città eterna.",
    "Torino è un comune italiano di 835699 abitanti (al 31 maggio 2023), capoluogo della regione Piemonte e dell'omonima città metropolitana. Quarto comune italiano per popolazione e cuore di un'area metropolitana che conta circa 1,7 milioni di abitanti, Torino è il quarto complesso economico-produttivo del Paese (insieme a Milano e Genova componeva il triangolo industriale, centro dell'industrializzazione su larga scala dell'economia italiana alla fine del XIX secolo, e durante gli anni del boom economico) e costituisce uno dei maggiori poli universitari, artistici, turistici, scientifici e culturali d'Italia. Nel suo territorio sono inoltre presenti aree ed edifici inclusi in due beni protetti dall'UNESCO: alcuni palazzi e zone facenti parte del circuito delle residenze sabaude in Piemonte (patrimonio dell'umanità) e l'area delle colline del Po (riserva della biosfera).",
    "Firenze in epoca medievale e nel linguaggio poetico anche Fiorenza, è un comune italiano di 360444 abitanti, capoluogo della Toscana e dell'omonima città metropolitana; è il primo comune della regione per popolazione e centro dell'area metropolitana di Firenze-Prato-Pistoia. Nel Medioevo è stata un importantissimo centro artistico, culturale, commerciale, politico, economico e finanziario; nell'età moderna ha ricoperto il ruolo di capitale del Granducato di Toscana dal 1569 al 1859 che, col governo delle famiglie dei Medici e dei Lorena, divenne uno degli stati più ricchi e moderni d'Italia. Le varie vicissitudini politiche, la potenza finanziaria e mercantile e le influenze in ogni campo della cultura hanno fatto della città un crocevia fondamentale della storia italiana ed europea. Nel 1865 Firenze fu proclamata capitale del Regno d'Italia (seconda, dopo Torino), mantenendo questo status fino al 1871, anno che segna la fine del Risorgimento e il passaggio del testimone a Roma.",
    "Venezia è un comune italiano di 249684 abitanti, capoluogo dell'omonima città metropolitana e della regione Veneto. Primo comune della regione Veneto per superficie e secondo per popolazione dopo Verona, è tra le primissime città nel mondo per bellezza ed importanza storica, artistica e culturale. Comprende sia territori insulari sia di terraferma ed è articolato attorno ai due principali centri di Venezia (al centro dell'omonima laguna) e di Mestre (nella terraferma).La città è stata per 1.100 anni la capitale della Serenissima Repubblica di Venezia ed è conosciuta a questo riguardo come la Serenissima, la Dominante e la Regina dell'Adriatico: per le peculiarità urbanistiche e per il suo patrimonio artistico, è universalmente considerata una tra le più belle città del mondo, dichiarata, assieme alla sua laguna, patrimonio dell'umanità dall'UNESCO, che ha contribuito a farne la seconda città italiana dopo Roma con il più alto flusso turistico. Insieme a Cannes e Berlino, è considerata una delle capitali del cinema europeo, grazie alla Mostra internazionale d'arte cinematografica."
];
const cities = [
    "Milano",
    "Roma",
    "Torino",
    "Firenze",
    "Venezia"
]

document.addEventListener("DOMContentLoaded",() => update())
selected.addEventListener("change", () => update());

function update() {
    image.src = images[selected.value];
    city.textContent = cities[selected.value];
    description.textContent = descriptions[selected.value];
}