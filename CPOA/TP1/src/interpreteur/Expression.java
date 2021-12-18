package interpreteur;

public interface Expression {
    int valeur();

    String toStringPrefix();

    String toStringPostfix();

    int nombreNombre();
}
