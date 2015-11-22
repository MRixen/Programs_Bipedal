function ComDeltaRobot()
    %
    % Projektarbeit im Rahmen der Vorlesung PKS
    %
    % Manuel-Leonhard Rixen
    %
    % Funktion: 
    % �bertragen der Koordinaten zum Verfahren der Delta Kinematik
    %
    % Fehler:
    % Fehlerhaftes Referenzieren 
    %(Ausgangsposition wird hin und wieder nicht korrekt angefahren)
    % Werden die Koordinaten ohne Pause �bertragen kommt es zu Datenverlust
    % bzw. kommt es zu "Datensalat"
    % (Daten�bertragun wurde �berpr�ft)
    % Die Positionen werden nicht immer gleich angefahren
    %
    % Hinweise:
    % Die Pausenzeit pTime ist ein grob ermittelter Wert. 
    % pTime < 0.8 scheint die Daten�bertragung nicht mehr korrekt zu
    % funtkionieren.    
    
    pTime = 0.8;
    
    % Port festlegen (Einstellungen unter Windows pr�fen!)
    PortID = serial( 'COM3' );
    set( PortID,'BaudRate',9600, 'StopBits', 2);
    
    % COM Port �ffnen
    fopen( PortID );
    
    fprintf(PortID,'1;30;55;');
    pause(pTime);
    
    fprintf(PortID,'1;30;0;');
    pause(pTime);

    fprintf(PortID,'1;30;55;');
    pause(pTime);
    
    fprintf(PortID,'1;30;0;');
    pause(pTime);
    
    % COM Port schlie�en
    OutPort = instrfind('Port','COM3');
    NewObjs = instrfind;
    fclose(NewObjs);   
end