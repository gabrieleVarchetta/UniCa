package it.unica.pr2.corrente;

import java.util.*;

public class TestCorrente {
	public static void main(String[] args) {

		// 18
		Object[] oggetti = new Object[] {
			new it.unica.pr2.corrente.devices.PresaElettrica(2000), // max Watt supportati (fornisce corrente)
			new it.unica.pr2.corrente.devices.Lampada(100), // Watt consumati (consuma corrente)
			new it.unica.pr2.corrente.devices.Scaldabagno(1300) // Watt consumati (consuma corrente)
		};

		List<InputDevice> inputDevices = new ArrayList<InputDevice>();
		List<OutputDevice> outputDevices = new ArrayList<OutputDevice>();
		for(int i=0; i< oggetti.length; i++) {
			if( ((Device)oggetti[i]).isInput() ) {
				inputDevices.add((InputDevice)oggetti[i]);
			}

			if( ((Device)oggetti[i]).isOutput() ) {
				outputDevices.add((OutputDevice)oggetti[i]);
			}
		}
		// 20
		assert inputDevices.size() == 2 &&
			inputDevices.get(0).equals(oggetti[1]) &&
			inputDevices.get(1).equals(oggetti[2]);

		assert outputDevices.size() == 1 &&
			outputDevices.get(0).equals(oggetti[0]);

		// 22
		assert !((Object)inputDevices.get(0) instanceof OutputDevice);
		assert !((Object)inputDevices.get(1) instanceof OutputDevice);
		assert !((Object)outputDevices.get(0) instanceof InputDevice);

		// 25
		for(InputDevice i : inputDevices) {
			assert !(i.isOn()); // off se sconnessi da presa
		}

		// connessione a presa
		inputDevices.get(0).connectTo(outputDevices.get(0));
		inputDevices.get(1).connectTo(outputDevices.get(0));
		for(InputDevice i: inputDevices) {
			assert !i.isOn(); // ancora off perche' la presa non ha corrente
		}

		outputDevices.get(0).setToOn(true); // la presa ora ha corrente
		for(InputDevice i: inputDevices) {
			assert i.isOn(); // i dispositivi sono accesi
		}

		outputDevices.get(0).setToOn(false);

		for(InputDevice i: inputDevices) {
			assert !i.isOn(); // di nuovo spenti
		}

		// 28
		OutputDevice presa = outputDevices.get(0);
		assert presa.wattSupportati() == 2000;
		assert presa.wattIstantanei() == 0;
		presa.setToOn(true);
		assert presa.wattSupportati() == 2000;
		assert presa.wattIstantanei() == 100 + 1300;


		// 30
		try {
			new it.unica.pr2.corrente.devices.Scaldabagno(1100).connectTo(presa);
			assert false;
		} catch(SaltataLaCorrente e) {
			assert true;
		}

		assert presa.wattIstantanei() == 0; // la presa e' off dopo che e' saltata la corrente
		presa.setToOn(true);
		assert presa.wattSupportati() == 2000;
		assert presa.wattIstantanei() == 100 + 1300;
		
		// overflow [bragging rights]
	

		presa.setToOn(false);
		assert presa.wattSupportati() == 2000;
		assert presa.wattIstantanei() == 0;

		try {
			new it.unica.pr2.corrente.devices.Scaldabagno(1100).connectTo(presa);
			assert true;
		} catch(SaltataLaCorrente e) {
			assert false;
		}

		try {
			presa.setToOn(true);
			assert false;
		} catch(SaltataLaCorrente e) {
			assert true;
		}/**/
	}

}
