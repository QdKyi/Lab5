package ua.lviv.iot.ExtremeSportEquipment.writer;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Writer;
import java.util.List;

import ua.lviv.iot.ExtremeSportEquipment.model.AbstractExtremeSportEquipment;

public class EquipmentWriter {
    
    private Writer writer;
    
    public void writeToFile(List<AbstractExtremeSportEquipment> equipment) throws IOException {
        
        String textToWrite;
        for (AbstractExtremeSportEquipment equip : equipment) {
            
            textToWrite = equip.getHeaders() + ", " + equip.toCSV() + "\r\n";
            writer.write(textToWrite);
        }
        writer.flush();
    }
    
    public void setWriter(Writer writer) {
        this.writer = writer;
    }
    
    public String toString() {
        return writer.toString();
    }
}
