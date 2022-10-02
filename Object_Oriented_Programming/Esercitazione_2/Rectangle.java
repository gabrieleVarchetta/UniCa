class Rectangle {
    double base = 30, height = 10;

    void scaleRect(double scalingFactor) {
        base *= scalingFactor;
        height *= scalingFactor;
    }
    
    void printEdges() {
        System.out.println("Base: " + base);
        System.out.println("Altezza: " + height);
    }
}
