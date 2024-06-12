import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;

public class ConvertToUpperCase {
    public static void main(String[] args) {
        long t1 = System.currentTimeMillis();

        try {
            // Read the file
            Path path = Paths.get("1000mb (copy).txt");
            byte[] bytes = Files.readAllBytes(path);
            String text = new String(bytes, StandardCharsets.UTF_8);

            // Convert to uppercase
            text = text.toUpperCase();

            // Write the file
            Files.write(path, text.getBytes(StandardCharsets.UTF_8));
        } catch (IOException e) {
            e.printStackTrace();
        }

        long t2 = System.currentTimeMillis();
        System.out.println((t2 - t1) / 1000.0 + " seconds");
    }
}
