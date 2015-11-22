function ComDeltaRobot()
    %
    % Projektarbeit im Rahmen der Vorlesung PKS
    %
    % Manuel-Leonhard Rixen
    %
    % Funktion: 
    % Übertragen der Koordinaten zum Verfahren der Delta Kinematik
    %
    % Fehler:
    % Fehlerhaftes Referenzieren 
    %(Ausgangsposition wird hin und wieder nicht korrekt angefahren)
    % Werden die Koordinaten ohne Pause übertragen kommt es zu Datenverlust
    % bzw. kommt es zu "Datensalat"
    % (Datenübertragun wurde überprüft)
    % Die Positionen werden nicht immer gleich angefahren
    %
    % Hinweise:
    % Die Pausenzeit pTime ist ein grob ermittelter Wert. 
    % pTime < 0.8 scheint die Datenübertragung nicht mehr korrekt zu
    % funtkionieren.    
    
    pTime = 0.8;
    
    % Port festlegen (Einstellungen unter Windows prüfen!)
    PortID = serial( 'COM3' );
    set( PortID,'BaudRate',9600, 'StopBits', 2);
    
    % COM Port öffnen
    fopen( PortID );
    
    fprintf(PortID,'1;30;55;');
    pause(pTime);
    
    fprintf(PortID,'1;30;0;');
    pause(pTime);

    fprintf(PortID,'1;30;55;');
    pause(pTime);
    
    fprintf(PortID,'1;30;0;');
    pause(pTime);
    
    % COM Port schließen
    OutPort = instrfind('Port','COM3');
    NewObjs = instrfind;
    fclose(NewObjs);   
end