package eccezioni;

public class FormatoNonSupportato extends IllegalArgumentException {
    public FormatoNonSupportato(String errMsg) {
        super(errMsg);
    }
}