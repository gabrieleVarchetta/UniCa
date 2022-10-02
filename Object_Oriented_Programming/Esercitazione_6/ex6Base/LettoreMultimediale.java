import classi.*;
import eccezioni.*;

public class LettoreMultimediale {
	public static void main(String[] args){
		
		//Test Prima Parte
		//Test su canzone
		Canzone canzoneTest = new Canzone("Song", "MP3",3);

		assert canzoneTest.getDurata() == 3; //La canzone ha durata 3?
		assert canzoneTest.getTitolo().equals("Song"); //La canzone ha titolo Song?
		assert canzoneTest.getVolume() == 0; //La canzone ha volume 0?

		String res = canzoneTest.esegui();

		assert res.equals("SongSongSong"); //L'esecuzione avviene come previsto?

		canzoneTest.louder();
		res = canzoneTest.esegui();

		assert res.equals("SongSongSong!"); //Il volume viene mostrato all'esecuzione?
		
		//Test su foto

		Foto fotoTest = new Foto("Sfondo", "JPG");

		String res3 = fotoTest.esegui();

		assert res3.equals("Sfondo"); //L'esecuzione avviene come previsto?

		fotoTest.brighter();
		res3 = fotoTest.esegui();

		assert res3.equals("Sfondo*"); //La luminosità viene mostrata all'esecuzione?

		//Test su film
		
		Filmato filmTest = new Filmato("Matrix", "MP4", 4);

		String res2 = filmTest.esegui();

		assert res2.equals("MatrixMatrixMatrixMatrix"); //L'esecuzione avviene come previsto?

		filmTest.louder();
		filmTest.brighter();
		res2 = filmTest.esegui();

		assert res2.equals("MatrixMatrixMatrixMatrix!*"); //Volume e Luminosità vengono mostrati all'esecuzione?

		//Test Seconda Parte
		//Test sulle eccezioni
		
		try {
            new Canzone("Andrea","MP4",3);
        } catch(FormatoNonSupportato e) {
            System.out.println("Eccezione Corretta");
        }

		try {
            new Foto("Cielo","JPEGI");
        } catch(FormatoNonSupportato e) {
            System.out.println("Eccezione Corretta");
        }

		try {
            new Filmato("Avatar","MP3",5);
        } catch(FormatoNonSupportato e) {
            System.out.println("Eccezione Lanciata Correttamente");
        }
	}
}

