��    A      $  Y   ,      �  	   �  "   �  >   �     �       "   +  
   N     Y     e  %   �  &   �     �     �  /   �  '        @     V  %   \  M   �  (   �  q   �     k     z     �     �  &   �  $   �     	     	     %	     B	     K	  '   c	  &   �	     �	  $   �	     �	  .   
  �   7
  *   �
  ^     8   r     �    �  �   �     f     l     r     x     �     �     �     �     �     �  	   �          
     #  	   (  <   2     o     t     �  V  �     �  =   �  _   <  ,   �     �  $   �     �          !  :   ;  )   v     �     �  *   �  9   �          ;  +   C  [   o  -   �  �   �  "   �     �  *   �      �  F     E   c     �     �  &   �  	          &   1  ;   X     �     �  (   �  -   �    "  1   ;  �   m  \   �  $   X  _  }  �   �     �     �     �     �     �     �     �          !  #   ?     c     i     u     �  	   �  K   �     �  )   �     #           >       &   .          #   <             5   !             0   ;   /   A            ,          -   :                    9                         @      8       
       4   =              '   *   +          2   7          )          6      	       (                        3          $      ?   "           1   %        (custom)  command not found, cannot proceed  couldn't be executed successfully. You must run this as root!  not found. Is grub2 installed? (new Entries) Add a script to your configuration Add script BURG found! Configuration has been saved Couldn't mount the selected partition Couldn't umount the selected partition Default title:  Device:  Do you want to configure BURG instead of grub2? Do you want to save your modifications? Edit grub preferences Entry Error while installing the bootloader Grub Customizer is a graphical interface to configure the grub2/burg settings Grub Customizer: Live CD setup Assistant Install the bootloader to MBR and put some
files to the bootloaders data directory
(if they don't already exist). Install to MBR Live-CD setup assistant Mount failed! Mount selected Filesystem Move down the selected entry or script Move up the selected entry or script Name the Entry No script found Please type a device string! Preview: Proxy binary not found! Remove a script from your configuration Save configuration and generate a new  Script to insert: Select and mount your root partition Select required submountpoints The bootloader has been installed successfully The generated configuration didn't equal to the saved configuration on startup. So what you see now may not be what you see when you restart your pc. To fix this, click update! The saved configuration is not up to date! These are the mountpoints of your fstab file.
Please select every grub/boot related partition. This seems not to be a root file system (no fstab found) Unmount mounted Filesystem You started Grub Customizer using the live CD.

Before you can edit your grub configuration we have to mount the required partitions.

This assistant will help you doing this.


If you mounted any partition of your installed system please unmount it, before you proceed! You will see all entries (uncustomized) when you run grub. This error accurs (in most cases), when you didn't install grub gustomizer currectly. _Edit _File _Help _Quit without saving _Quit without update _Save & Quit _Update & Quit _View _use another partition:  installing the bootloader… is active label loading configuration… name partition reload configuration (same effect as an application restart) type umount failed! updating configuration Project-Id-Version: 1.2
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2010-10-14 18:52+0200
PO-Revision-Date: 2010-10-13 15:35+0200
Last-Translator: Daniel Richter <danielrichter2007@web.de>
Language-Team: German
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
Plural-Forms: nplurals=2; plural=(n != 1);
  (angepasst) -Befehl nicht gefunden. Grub Customizer kann nicht fortfahren  konnte nicht erfolgreich ausgeführt werden. Sie müssen dieses Programm als Admin ausführen!  nicht gefinden. Ist Grub2/BURG installiert? (neue Einträge) Script zur Konfiguration hinzufügen Script hinzufügen BURG gefunden! Konfiguration gespeichert Die ausgewählte Partition konnte nicht eingebunden werden Partition konnte nicht ausgehängt werden Vorgabetitel:  Gerät:  Wollen Sie statt Grub2 BURG konfigurieren? Sollen alle vorgenommenen Änderungen gespeichert werden? Grub-Einstellungen bearbeiten Eintrag Installation des Bootloaders fehlgeschlagen Grub Customizer ist eine grafische Schnittstelle zur Anpassung der grub2/burg-Einstellungen Grub Customizer: LiveCD-Einrichtungsassistent Dieser Dialog wird den Bootloader in den Master Boot Record
übertragen. Ggf. werden einige Dateien im Daten-Verzeichnis
des Bootloaders neu angelegt. Bootloader in den MBR installieren LiveCD-Einrichtungsassistent Partition konnte nicht eingebunden werden! Gewähltes Dateisystem einbinden Aktuellen Eintrag / aktuelles Script eine Position nach unten schieben Aktuellen Eintrag / aktuelles Script eine Position nach oben schieben Geben Sie eine Bezeichnung ein! Keine Skripte gefunden Bitte geben Sie einen Geräte-Pfad ein Vorschau: Proxy-Anwendung nicht gefunden! Script aus der Konfiguration entfernen Konfiguration speichern und folgende Datei neu generieren:  Einzufügendes Script: Wählen Sie Ihre Root-Partition Wählen Sie alle notwendigen Mountpoints Der Bootloader wurde erfolgreich installiert! Die generierte Konfiguration entsprach nicht der gespeicherten Konfiguration, als Sie dieses Programm gestartet haben. Dies kann dazu führen, dass die Anzeige im Bootloader nicht der Anzeige dieses Programms entspricht Um dieses Problem zu beheben, klicken Sie auf Aktualisieren! Die gespeicherte Konfiguration ist nicht aktuell! Diese Mountpoints befinden sich in Ihrer fstab.
Bitte wählen Sie alle Partitionen, die zum
Generieren der Grub-Konfiguration notwendig sind. Bei dieser Partition scheint es sich nicht um ein Wurzeldateisystem zu handeln (fstab fehlt) Eingebundenes Dateisystem aushängen Sie haben den Grub Customizer von einer Live-CD aus gestartet.

Bevor Sie Ihre Grub-Konfiguration bearbeiten können, müssen
noch einige Partitionen eingebunden werden.

Dieser Assistent wird Sie dabei unterstützen.


Sofern Sie vor dem Start dieses Programms weitere Partitionen eingebunden haben
Sollten Sie diese aushängen, bevor Sie fortfahren! Wenn Sie Grub das nächste mal starten, sehen Sie alle Einträge (unverändert).Dieser Fehler tritt in der Regel dann auf wenn der Grub Customizer nicht korrekt installiert wurde _Bearbeiten _Datei _Hilfe _Beenden, ohne zu speichern _Beenden, ohne zu aktualisieren _Speichern und Beenden _Aktualisieren und Beenden _Ansicht _Andere Partition verwenden:  der Bootloaders wird installiert… Aktiv Bezeichnung Konfiguration wird geladen… Bezeichnung Partition Konfiguration erneut laden (gleicher Effekt wie bei Neustart des Programms) Typ Partition konnte nicht ausgehängt werden Konfiguration wird aktualisiert 