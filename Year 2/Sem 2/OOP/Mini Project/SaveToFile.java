// Interface for saving to file
public interface SaveToFile {
    void saveToFile();
    void loadFromFile(String filename) throws IOException, ClassNotFoundException;
} 