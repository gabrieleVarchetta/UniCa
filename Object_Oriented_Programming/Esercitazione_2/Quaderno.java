class Quaderno {
    int nPages = 0;
    String title = "";

    void addPages(int nPages) {
        this.nPages += nPages;
    }

    void removePages(int nPages) {
        this.nPages -= nPages;
    }

    void assignTitle(String title) {
        this.title = title;
    }

    void printAttributes() {
        System.out.println("Numero pagine: " + nPages);
        System.out.println("Titolo: " + title);
    }
}
