# Outrun Arcade Cabinet Retromod

Retromodding an original Outrun arcade cabinet to run modern racing sim games.

We scored an original Outrun arcade cabinet in pretty rough condition and decided to retromod it to run modern racing sim games.

This project is a work in progress and is semi-kinda-relatively functional but still a total mess.

So far we've gotted out the original electronics and monitor (and stored them safely) and replaced them with a gaming PC running Steam so we can play Assetto Corsa and BeamNG.drive.

We've build some custom looms that let the original pedals/steering/shifter plug into the PC via USB using an Arduino Pro Micro.

We've also replaced the original CRT monitor with a random old LCD monitor and mounted it in the cabinet.

![Outrun Arcade Cabinet](https://github.com/senwerks/outrun-arcade/blob/main/meta/outrun-arcade-01.jpg)
![Outrun Arcade Cabinet](https://github.com/senwerks/outrun-arcade/blob/main/meta/outrun-arcade-02.jpg)


## TODO

- [x] Finish getting the Arduino Pro Micro to read the original pedals/steering/shifter and send the inputs to the PC
- [x] Design/print a PETG version of the broken steering gear so we can test-reassemble the steering system
- [x] Design/print a switch-plate to hold 2 switches at either side of the shifter, to convert H/L toggle into a USB sequential shifter
- [x] Add springs to convert the H/L toggle into a return-to-centre sequential shifter
- [ ] Design and 3D print a custom shroud that matches the LCD monitor to the original CRT monitor bezel (megabot??)
- [ ] Order a metal-printed copy of the gear once we know it works
- [ ] Tidy up the wiring and integrate power to the original cable
- [ ] Mount the PC better in the cabinet and build a see-through arcrylic panel to protect it (and show it off!)
- [ ] Put a beasty sound system in it for that sweet sweet immersion
- [ ] Get the original coin mech working and tie it into Steam as an input? Or a coin/token unlocks the screensaver?
- [ ] Stretch goal: Get the motion system working!

## Progress Photos

The original shifter was a "High/Low" toggle lever that closed a switch when moved in one direction and released that switch when moved in the other. We couldn't think of a simple way to make a single switch be mapped to "Shift Up" and "Shift Down" in the games, so we had to convert the toggle lever into a "return to center" lever using springs, and then 3D printed a switch-plate that holds 2 switches either side. We then added another Pro Micro and used that to map those switches to simulate Xbox controller buttons.

![Original OutRun Shifter](https://github.com/senwerks/outrun-arcade/blob/main/meta/outrun-arcade-old-shifter.jpg)

![OutRun Shifter converted to Sequential Shifter](https://github.com/senwerks/outrun-arcade/blob/main/meta/outrun-arcade-shifter.jpg)

