package shared;

import java.io.Serializable;

public class Coordinata implements Serializable{
    private static final long serialVersionUID = 23;

    private double latitudine;
    private double longitudine;

    // Costruttore
    public Coordinata(double latitudine, double longitudine) {
        // Verifica che le coordinate siano valide
        if (isValidLatitudine(latitudine) && isValidLongitudine(longitudine)) {
            this.latitudine = latitudine;
            this.longitudine = longitudine;
        } else {
            throw new IllegalArgumentException("Coordinate non valide");
        }
    }

    // Metodo per ottenere la latitudine
    public double getLatitudine() {
        return latitudine;
    }

    // Metodo per ottenere la longitudine
    public double getLongitudine() {
        return longitudine;
    }

    // Verifica la validità della latitudine
    private boolean isValidLatitudine(double latitudine) {
        return latitudine >= -90 && latitudine <= 90;
    }

    // Verifica la validità della longitudine
    private boolean isValidLongitudine(double longitudine) {
        return longitudine >= -180 && longitudine <= 180;
    }


    // Metodo per calcolare la distanza tra due coordinate
    public double calcolaDistanza(Coordinata altraCoordinate) {
        double latitudineAltra = altraCoordinate.getLatitudine();
        double longitudineAltra = altraCoordinate.getLongitudine();

        // Formula di Haversine per calcolare la distanza tra due punti sulla superficie sferica
        double R = 6371; // Raggio medio della Terra in chilometri
        double deltaLat = Math.toRadians(latitudineAltra - this.latitudine);
        double deltaLon = Math.toRadians(longitudineAltra - this.longitudine);

        double a = Math.sin(deltaLat / 2) * Math.sin(deltaLat / 2)
                + Math.cos(Math.toRadians(this.latitudine)) * Math.cos(Math.toRadians(latitudineAltra))
                * Math.sin(deltaLon / 2) * Math.sin(deltaLon / 2);

        double c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));

        return R * c;
    }


    // Metodo per verificare se le coordinate sono entro un certo raggio da un'altra coordinata
    public boolean sonoEntroRaggio(Coordinata altraCoordinate, double raggio) {
        double distanza = calcolaDistanza(altraCoordinate);
        return distanza <= raggio;
    }


    // Metodo per ottenere una rappresentazione stringa delle coordinate
    @Override
    public String toString() {
        return "(" + latitudine + ", " + longitudine + ")";
    }
}
