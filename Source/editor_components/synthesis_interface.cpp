/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "synthesis_interface.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SynthesisInterface::SynthesisInterface ()
{
    addAndMakeVisible (step_sequencer_ = new GraphicalStepSequencer (16));
    addAndMakeVisible (amplitude_envelope_ = new GraphicalEnvelope());
    addAndMakeVisible (filter_envelope_ = new GraphicalEnvelope());
    addAndMakeVisible (osc_1_wave_display_ = new WaveFormSelector (128));
    addAndMakeVisible (osc_2_wave_display_ = new WaveFormSelector (128));
    addAndMakeVisible (polyphony_ = new Slider ("polyphony"));
    polyphony_->setRange (1, 32, 1);
    polyphony_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    polyphony_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    polyphony_->addListener (this);

    addAndMakeVisible (portamento_ = new Slider ("portamento"));
    portamento_->setRange (0, 0.2, 0);
    portamento_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    portamento_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    portamento_->addListener (this);

    addAndMakeVisible (pitch_bend_range_ = new Slider ("pitch bend range"));
    pitch_bend_range_->setRange (0, 48, 1);
    pitch_bend_range_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    pitch_bend_range_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    pitch_bend_range_->addListener (this);

    addAndMakeVisible (cross_modulation_ = new Slider ("cross modulation"));
    cross_modulation_->setRange (0, 10, 0);
    cross_modulation_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    cross_modulation_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    cross_modulation_->addListener (this);
    cross_modulation_->setSkewFactor (0.5);

    addAndMakeVisible (filter_response_ = new FilterResponse (128));
    addAndMakeVisible (legato_ = new Slider ("legato"));
    legato_->setRange (0, 1, 1);
    legato_->setSliderStyle (Slider::LinearHorizontal);
    legato_->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    legato_->addListener (this);

    addAndMakeVisible (portamento_type_ = new Slider ("portamento type"));
    portamento_type_->setRange (0, 2, 1);
    portamento_type_->setSliderStyle (Slider::LinearHorizontal);
    portamento_type_->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    portamento_type_->addListener (this);

    addAndMakeVisible (osc_mix_ = new Slider ("osc mix"));
    osc_mix_->setRange (0, 1, 0);
    osc_mix_->setSliderStyle (Slider::LinearBar);
    osc_mix_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    osc_mix_->setColour (Slider::backgroundColourId, Colours::black);
    osc_mix_->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    osc_mix_->addListener (this);

    addAndMakeVisible (osc_2_transpose_ = new Slider ("osc 2 transpose"));
    osc_2_transpose_->setRange (-48, 48, 1);
    osc_2_transpose_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    osc_2_transpose_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    osc_2_transpose_->addListener (this);

    addAndMakeVisible (osc_2_tune_ = new Slider ("osc 2 tune"));
    osc_2_tune_->setRange (-1, 1, 0);
    osc_2_tune_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    osc_2_tune_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    osc_2_tune_->addListener (this);

    addAndMakeVisible (volume_ = new Slider ("volume"));
    volume_->setRange (0, 1, 0);
    volume_->setSliderStyle (Slider::LinearHorizontal);
    volume_->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volume_->addListener (this);
    volume_->setSkewFactor (0.3);

    addAndMakeVisible (delay_time_ = new Slider ("delay time"));
    delay_time_->setRange (0.01, 1, 0);
    delay_time_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delay_time_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    delay_time_->addListener (this);
    delay_time_->setSkewFactor (2);

    addAndMakeVisible (delay_feedback_ = new Slider ("delay feedback"));
    delay_feedback_->setRange (-1, 1, 0);
    delay_feedback_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delay_feedback_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    delay_feedback_->addListener (this);

    addAndMakeVisible (delay_dry_wet_ = new Slider ("delay dry wet"));
    delay_dry_wet_->setRange (0, 1, 0);
    delay_dry_wet_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delay_dry_wet_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    delay_dry_wet_->addListener (this);

    addAndMakeVisible (velocity_track_ = new Slider ("velocity track"));
    velocity_track_->setRange (-1, 1, 0);
    velocity_track_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    velocity_track_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    velocity_track_->addListener (this);

    addAndMakeVisible (amp_attack_ = new Slider ("amp attack"));
    amp_attack_->setRange (0, 10, 0);
    amp_attack_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    amp_attack_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    amp_attack_->addListener (this);
    amp_attack_->setSkewFactor (0.3);

    addAndMakeVisible (amp_decay_ = new Slider ("amp decay"));
    amp_decay_->setRange (0, 10, 0);
    amp_decay_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    amp_decay_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    amp_decay_->addListener (this);
    amp_decay_->setSkewFactor (0.3);

    addAndMakeVisible (amp_release_ = new Slider ("amp release"));
    amp_release_->setRange (0, 10, 0);
    amp_release_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    amp_release_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    amp_release_->addListener (this);
    amp_release_->setSkewFactor (0.3);

    addAndMakeVisible (amp_sustain_ = new Slider ("amp sustain"));
    amp_sustain_->setRange (0, 1, 0);
    amp_sustain_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    amp_sustain_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    amp_sustain_->addListener (this);

    addAndMakeVisible (fil_attack_ = new Slider ("fil attack"));
    fil_attack_->setRange (0, 10, 0);
    fil_attack_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fil_attack_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    fil_attack_->addListener (this);
    fil_attack_->setSkewFactor (0.3);

    addAndMakeVisible (fil_decay_ = new Slider ("fil decay"));
    fil_decay_->setRange (0, 10, 0);
    fil_decay_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fil_decay_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    fil_decay_->addListener (this);
    fil_decay_->setSkewFactor (0.3);

    addAndMakeVisible (fil_release_ = new Slider ("fil release"));
    fil_release_->setRange (0, 10, 0);
    fil_release_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fil_release_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    fil_release_->addListener (this);
    fil_release_->setSkewFactor (0.3);

    addAndMakeVisible (fil_sustain_ = new Slider ("fil sustain"));
    fil_sustain_->setRange (0, 1, 0);
    fil_sustain_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fil_sustain_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    fil_sustain_->addListener (this);

    addAndMakeVisible (resonance_ = new Slider ("resonance"));
    resonance_->setRange (0, 1, 0);
    resonance_->setSliderStyle (Slider::LinearBar);
    resonance_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    resonance_->setColour (Slider::backgroundColourId, Colours::black);
    resonance_->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    resonance_->addListener (this);

    addAndMakeVisible (filter_type_ = new Slider ("filter type"));
    filter_type_->setRange (0, 6, 1);
    filter_type_->setSliderStyle (Slider::LinearVertical);
    filter_type_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    filter_type_->addListener (this);

    addAndMakeVisible (osc_1_waveform_ = new Slider ("osc 1 waveform"));
    osc_1_waveform_->setRange (0, 11, 1);
    osc_1_waveform_->setSliderStyle (Slider::LinearBar);
    osc_1_waveform_->setTextBoxStyle (Slider::NoTextBox, true, 0, 0);
    osc_1_waveform_->setColour (Slider::backgroundColourId, Colours::black);
    osc_1_waveform_->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    osc_1_waveform_->addListener (this);

    addAndMakeVisible (osc_2_waveform_ = new Slider ("osc 2 waveform"));
    osc_2_waveform_->setRange (0, 11, 1);
    osc_2_waveform_->setSliderStyle (Slider::LinearBar);
    osc_2_waveform_->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    osc_2_waveform_->setColour (Slider::backgroundColourId, Colours::black);
    osc_2_waveform_->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    osc_2_waveform_->addListener (this);

    addAndMakeVisible (cutoff_ = new Slider ("cutoff"));
    cutoff_->setRange (28, 127, 0);
    cutoff_->setSliderStyle (Slider::LinearBar);
    cutoff_->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cutoff_->setColour (Slider::backgroundColourId, Colours::black);
    cutoff_->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    cutoff_->addListener (this);

    addAndMakeVisible (fil_env_depth_ = new Slider ("fil env depth"));
    fil_env_depth_->setRange (-128, 128, 0);
    fil_env_depth_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fil_env_depth_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    fil_env_depth_->addListener (this);

    addAndMakeVisible (keytrack_ = new Slider ("keytrack"));
    keytrack_->setRange (-1, 1, 0);
    keytrack_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    keytrack_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    keytrack_->addListener (this);

    addAndMakeVisible (osc_feedback_transpose_ = new Slider ("osc feedback transpose"));
    osc_feedback_transpose_->setRange (-24, 24, 1);
    osc_feedback_transpose_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    osc_feedback_transpose_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    osc_feedback_transpose_->addListener (this);

    addAndMakeVisible (osc_feedback_amount_ = new Slider ("osc feedback amount"));
    osc_feedback_amount_->setRange (-1, 1, 0);
    osc_feedback_amount_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    osc_feedback_amount_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    osc_feedback_amount_->addListener (this);

    addAndMakeVisible (osc_feedback_tune_ = new Slider ("osc feedback tune"));
    osc_feedback_tune_->setRange (-1, 1, 0);
    osc_feedback_tune_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    osc_feedback_tune_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    osc_feedback_tune_->addListener (this);

    addAndMakeVisible (amplitude_env_mod_source_ = new ModulationSource());
    addAndMakeVisible (step_generator_mod_source_ = new ModulationSource());
    addAndMakeVisible (filter_env_mod_source_ = new ModulationSource());
    addAndMakeVisible (cross_mod_destination_ = new ModulationDestination());
    addAndMakeVisible (pitch_mod_destination_ = new ModulationDestination());
    addAndMakeVisible (cutoff_mod_destination_ = new ModulationDestination());
    addAndMakeVisible (lfo_1_wave_display_ = new WaveFormSelector (128));
    addAndMakeVisible (lfo_2_wave_display_ = new WaveFormSelector (128));
    addAndMakeVisible (lfo_1_waveform_ = new Slider ("lfo 1 waveform"));
    lfo_1_waveform_->setRange (0, 11, 1);
    lfo_1_waveform_->setSliderStyle (Slider::LinearBar);
    lfo_1_waveform_->setTextBoxStyle (Slider::NoTextBox, true, 0, 0);
    lfo_1_waveform_->setColour (Slider::backgroundColourId, Colours::black);
    lfo_1_waveform_->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    lfo_1_waveform_->addListener (this);

    addAndMakeVisible (lfo_2_waveform_ = new Slider ("lfo 2 waveform"));
    lfo_2_waveform_->setRange (0, 11, 1);
    lfo_2_waveform_->setSliderStyle (Slider::LinearBar);
    lfo_2_waveform_->setTextBoxStyle (Slider::NoTextBox, true, 0, 0);
    lfo_2_waveform_->setColour (Slider::backgroundColourId, Colours::black);
    lfo_2_waveform_->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    lfo_2_waveform_->addListener (this);

    addAndMakeVisible (lfo_1_mod_source_ = new ModulationSource());
    addAndMakeVisible (lfo_2_mod_source_ = new ModulationSource());
    addAndMakeVisible (resonance_mod_destination_ = new ModulationDestination());
    addAndMakeVisible (arp_frequency_ = new Slider ("arp frequency"));
    arp_frequency_->setRange (1, 20, 0);
    arp_frequency_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    arp_frequency_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    arp_frequency_->addListener (this);
    arp_frequency_->setSkewFactor (0.5);

    addAndMakeVisible (arp_gate_ = new Slider ("arp gate"));
    arp_gate_->setRange (0, 1, 0);
    arp_gate_->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    arp_gate_->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    arp_gate_->addListener (this);


    //[UserPreSize]
    resonance_->setSliderStyle(Slider::LinearBarVertical);
    osc_1_waveform_->setSliderStyle(Slider::LinearBarVertical);
    osc_2_waveform_->setSliderStyle(Slider::LinearBarVertical);
    lfo_1_waveform_->setSliderStyle(Slider::LinearBarVertical);
    lfo_2_waveform_->setSliderStyle(Slider::LinearBarVertical);
    osc_mix_->setSliderStyle(Slider::LinearBarVertical);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    amplitude_envelope_->setAttackSlider(amp_attack_);
    amplitude_envelope_->setDecaySlider(amp_decay_);
    amplitude_envelope_->setSustainSlider(amp_sustain_);
    amplitude_envelope_->setReleaseSlider(amp_release_);

    filter_envelope_->setAttackSlider(fil_attack_);
    filter_envelope_->setDecaySlider(fil_decay_);
    filter_envelope_->setSustainSlider(fil_sustain_);
    filter_envelope_->setReleaseSlider(fil_release_);

    osc_1_wave_display_->setWaveSlider(osc_1_waveform_);
    osc_2_wave_display_->setWaveSlider(osc_2_waveform_);
    lfo_1_wave_display_->setWaveSlider(lfo_1_waveform_);
    lfo_2_wave_display_->setWaveSlider(lfo_2_waveform_);

    filter_response_->setCutoffSlider(cutoff_);
    filter_response_->setResonanceSlider(resonance_);
    filter_response_->setFilterTypeSlider(filter_type_);

    for (int i = 0; i < getNumChildComponents(); ++i) {
        Slider* slider = dynamic_cast<Slider*>(getChildComponent(i));
        if (slider)
            slider_lookup_[slider->getName().toStdString()] = slider;
    }
    //[/Constructor]
}

SynthesisInterface::~SynthesisInterface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    step_sequencer_ = nullptr;
    amplitude_envelope_ = nullptr;
    filter_envelope_ = nullptr;
    osc_1_wave_display_ = nullptr;
    osc_2_wave_display_ = nullptr;
    polyphony_ = nullptr;
    portamento_ = nullptr;
    pitch_bend_range_ = nullptr;
    cross_modulation_ = nullptr;
    filter_response_ = nullptr;
    legato_ = nullptr;
    portamento_type_ = nullptr;
    osc_mix_ = nullptr;
    osc_2_transpose_ = nullptr;
    osc_2_tune_ = nullptr;
    volume_ = nullptr;
    delay_time_ = nullptr;
    delay_feedback_ = nullptr;
    delay_dry_wet_ = nullptr;
    velocity_track_ = nullptr;
    amp_attack_ = nullptr;
    amp_decay_ = nullptr;
    amp_release_ = nullptr;
    amp_sustain_ = nullptr;
    fil_attack_ = nullptr;
    fil_decay_ = nullptr;
    fil_release_ = nullptr;
    fil_sustain_ = nullptr;
    resonance_ = nullptr;
    filter_type_ = nullptr;
    osc_1_waveform_ = nullptr;
    osc_2_waveform_ = nullptr;
    cutoff_ = nullptr;
    fil_env_depth_ = nullptr;
    keytrack_ = nullptr;
    osc_feedback_transpose_ = nullptr;
    osc_feedback_amount_ = nullptr;
    osc_feedback_tune_ = nullptr;
    amplitude_env_mod_source_ = nullptr;
    step_generator_mod_source_ = nullptr;
    filter_env_mod_source_ = nullptr;
    cross_mod_destination_ = nullptr;
    pitch_mod_destination_ = nullptr;
    cutoff_mod_destination_ = nullptr;
    lfo_1_wave_display_ = nullptr;
    lfo_2_wave_display_ = nullptr;
    lfo_1_waveform_ = nullptr;
    lfo_2_waveform_ = nullptr;
    lfo_1_mod_source_ = nullptr;
    lfo_2_mod_source_ = nullptr;
    resonance_mod_destination_ = nullptr;
    arp_frequency_ = nullptr;
    arp_gate_ = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SynthesisInterface::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff1f1f1f));

    //[UserPaint] Add your own custom painting code here..
    g.setColour(Colours::white);
    //[/UserPaint]
}

void SynthesisInterface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    step_sequencer_->setBounds (416, 288, 300, 100);
    amplitude_envelope_->setBounds (416, 392, 300, 100);
    filter_envelope_->setBounds (408, 152, 300, 100);
    osc_1_wave_display_->setBounds (40, 8, 240, 100);
    osc_2_wave_display_->setBounds (40, 112, 240, 100);
    polyphony_->setBounds (424, 552, 50, 50);
    portamento_->setBounds (424, 608, 50, 50);
    pitch_bend_range_->setBounds (576, 552, 50, 50);
    cross_modulation_->setBounds (320, 16, 50, 50);
    filter_response_->setBounds (408, 8, 300, 100);
    legato_->setBounds (488, 560, 64, 24);
    portamento_type_->setBounds (488, 616, 64, 24);
    osc_mix_->setBounds (280, 8, 20, 204);
    osc_2_transpose_->setBounds (320, 80, 50, 50);
    osc_2_tune_->setBounds (320, 144, 50, 50);
    volume_->setBounds (32, 552, 248, 24);
    delay_time_->setBounds (96, 496, 50, 50);
    delay_feedback_->setBounds (160, 496, 50, 50);
    delay_dry_wet_->setBounds (224, 496, 50, 50);
    velocity_track_->setBounds (680, 496, 50, 50);
    amp_attack_->setBounds (424, 496, 50, 50);
    amp_decay_->setBounds (480, 496, 50, 50);
    amp_release_->setBounds (592, 496, 50, 50);
    amp_sustain_->setBounds (536, 496, 50, 50);
    fil_attack_->setBounds (416, 256, 32, 32);
    fil_decay_->setBounds (456, 256, 32, 32);
    fil_release_->setBounds (536, 256, 32, 32);
    fil_sustain_->setBounds (496, 256, 32, 32);
    resonance_->setBounds (708, 8, 12, 100);
    filter_type_->setBounds (752, 8, 24, 96);
    osc_1_waveform_->setBounds (28, 8, 12, 100);
    osc_2_waveform_->setBounds (28, 112, 12, 100);
    cutoff_->setBounds (408, 108, 300, 12);
    fil_env_depth_->setBounds (624, 256, 32, 32);
    keytrack_->setBounds (664, 256, 32, 32);
    osc_feedback_transpose_->setBounds (64, 224, 50, 50);
    osc_feedback_amount_->setBounds (200, 224, 50, 50);
    osc_feedback_tune_->setBounds (128, 224, 50, 50);
    amplitude_env_mod_source_->setBounds (728, 424, 24, 24);
    step_generator_mod_source_->setBounds (728, 328, 24, 24);
    filter_env_mod_source_->setBounds (720, 184, 24, 24);
    cross_mod_destination_->setBounds (368, 32, 24, 24);
    pitch_mod_destination_->setBounds (368, 88, 24, 24);
    cutoff_mod_destination_->setBounds (720, 8, 24, 24);
    lfo_1_wave_display_->setBounds (40, 280, 240, 100);
    lfo_2_wave_display_->setBounds (40, 384, 240, 100);
    lfo_1_waveform_->setBounds (28, 280, 12, 100);
    lfo_2_waveform_->setBounds (28, 384, 12, 100);
    lfo_1_mod_source_->setBounds (288, 320, 24, 24);
    lfo_2_mod_source_->setBounds (288, 424, 24, 24);
    resonance_mod_destination_->setBounds (680, 120, 24, 24);
    arp_frequency_->setBounds (176, 576, 50, 50);
    arp_gate_->setBounds (88, 576, 50, 50);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SynthesisInterface::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    controls_[sliderThatWasMoved->getName().toStdString()]->set(sliderThatWasMoved->getValue());
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == polyphony_)
    {
        //[UserSliderCode_polyphony_] -- add your slider handling code here..
        //[/UserSliderCode_polyphony_]
    }
    else if (sliderThatWasMoved == portamento_)
    {
        //[UserSliderCode_portamento_] -- add your slider handling code here..
        //[/UserSliderCode_portamento_]
    }
    else if (sliderThatWasMoved == pitch_bend_range_)
    {
        //[UserSliderCode_pitch_bend_range_] -- add your slider handling code here..
        //[/UserSliderCode_pitch_bend_range_]
    }
    else if (sliderThatWasMoved == cross_modulation_)
    {
        //[UserSliderCode_cross_modulation_] -- add your slider handling code here..
        //[/UserSliderCode_cross_modulation_]
    }
    else if (sliderThatWasMoved == legato_)
    {
        //[UserSliderCode_legato_] -- add your slider handling code here..
        //[/UserSliderCode_legato_]
    }
    else if (sliderThatWasMoved == portamento_type_)
    {
        //[UserSliderCode_portamento_type_] -- add your slider handling code here..
        //[/UserSliderCode_portamento_type_]
    }
    else if (sliderThatWasMoved == osc_mix_)
    {
        //[UserSliderCode_osc_mix_] -- add your slider handling code here..
        //[/UserSliderCode_osc_mix_]
    }
    else if (sliderThatWasMoved == osc_2_transpose_)
    {
        //[UserSliderCode_osc_2_transpose_] -- add your slider handling code here..
        //[/UserSliderCode_osc_2_transpose_]
    }
    else if (sliderThatWasMoved == osc_2_tune_)
    {
        //[UserSliderCode_osc_2_tune_] -- add your slider handling code here..
        //[/UserSliderCode_osc_2_tune_]
    }
    else if (sliderThatWasMoved == volume_)
    {
        //[UserSliderCode_volume_] -- add your slider handling code here..
        //[/UserSliderCode_volume_]
    }
    else if (sliderThatWasMoved == delay_time_)
    {
        //[UserSliderCode_delay_time_] -- add your slider handling code here..
        //[/UserSliderCode_delay_time_]
    }
    else if (sliderThatWasMoved == delay_feedback_)
    {
        //[UserSliderCode_delay_feedback_] -- add your slider handling code here..
        //[/UserSliderCode_delay_feedback_]
    }
    else if (sliderThatWasMoved == delay_dry_wet_)
    {
        //[UserSliderCode_delay_dry_wet_] -- add your slider handling code here..
        //[/UserSliderCode_delay_dry_wet_]
    }
    else if (sliderThatWasMoved == velocity_track_)
    {
        //[UserSliderCode_velocity_track_] -- add your slider handling code here..
        //[/UserSliderCode_velocity_track_]
    }
    else if (sliderThatWasMoved == amp_attack_)
    {
        //[UserSliderCode_amp_attack_] -- add your slider handling code here..
        //[/UserSliderCode_amp_attack_]
    }
    else if (sliderThatWasMoved == amp_decay_)
    {
        //[UserSliderCode_amp_decay_] -- add your slider handling code here..
        //[/UserSliderCode_amp_decay_]
    }
    else if (sliderThatWasMoved == amp_release_)
    {
        //[UserSliderCode_amp_release_] -- add your slider handling code here..
        //[/UserSliderCode_amp_release_]
    }
    else if (sliderThatWasMoved == amp_sustain_)
    {
        //[UserSliderCode_amp_sustain_] -- add your slider handling code here..
        //[/UserSliderCode_amp_sustain_]
    }
    else if (sliderThatWasMoved == fil_attack_)
    {
        //[UserSliderCode_fil_attack_] -- add your slider handling code here..
        //[/UserSliderCode_fil_attack_]
    }
    else if (sliderThatWasMoved == fil_decay_)
    {
        //[UserSliderCode_fil_decay_] -- add your slider handling code here..
        //[/UserSliderCode_fil_decay_]
    }
    else if (sliderThatWasMoved == fil_release_)
    {
        //[UserSliderCode_fil_release_] -- add your slider handling code here..
        //[/UserSliderCode_fil_release_]
    }
    else if (sliderThatWasMoved == fil_sustain_)
    {
        //[UserSliderCode_fil_sustain_] -- add your slider handling code here..
        //[/UserSliderCode_fil_sustain_]
    }
    else if (sliderThatWasMoved == resonance_)
    {
        //[UserSliderCode_resonance_] -- add your slider handling code here..
        //[/UserSliderCode_resonance_]
    }
    else if (sliderThatWasMoved == filter_type_)
    {
        //[UserSliderCode_filter_type_] -- add your slider handling code here..
        //[/UserSliderCode_filter_type_]
    }
    else if (sliderThatWasMoved == osc_1_waveform_)
    {
        //[UserSliderCode_osc_1_waveform_] -- add your slider handling code here..
        //[/UserSliderCode_osc_1_waveform_]
    }
    else if (sliderThatWasMoved == osc_2_waveform_)
    {
        //[UserSliderCode_osc_2_waveform_] -- add your slider handling code here..
        //[/UserSliderCode_osc_2_waveform_]
    }
    else if (sliderThatWasMoved == cutoff_)
    {
        //[UserSliderCode_cutoff_] -- add your slider handling code here..
        //[/UserSliderCode_cutoff_]
    }
    else if (sliderThatWasMoved == fil_env_depth_)
    {
        //[UserSliderCode_fil_env_depth_] -- add your slider handling code here..
        //[/UserSliderCode_fil_env_depth_]
    }
    else if (sliderThatWasMoved == keytrack_)
    {
        //[UserSliderCode_keytrack_] -- add your slider handling code here..
        //[/UserSliderCode_keytrack_]
    }
    else if (sliderThatWasMoved == osc_feedback_transpose_)
    {
        //[UserSliderCode_osc_feedback_transpose_] -- add your slider handling code here..
        //[/UserSliderCode_osc_feedback_transpose_]
    }
    else if (sliderThatWasMoved == osc_feedback_amount_)
    {
        //[UserSliderCode_osc_feedback_amount_] -- add your slider handling code here..
        //[/UserSliderCode_osc_feedback_amount_]
    }
    else if (sliderThatWasMoved == osc_feedback_tune_)
    {
        //[UserSliderCode_osc_feedback_tune_] -- add your slider handling code here..
        //[/UserSliderCode_osc_feedback_tune_]
    }
    else if (sliderThatWasMoved == lfo_1_waveform_)
    {
        //[UserSliderCode_lfo_1_waveform_] -- add your slider handling code here..
        //[/UserSliderCode_lfo_1_waveform_]
    }
    else if (sliderThatWasMoved == lfo_2_waveform_)
    {
        //[UserSliderCode_lfo_2_waveform_] -- add your slider handling code here..
        //[/UserSliderCode_lfo_2_waveform_]
    }
    else if (sliderThatWasMoved == arp_frequency_)
    {
        //[UserSliderCode_arp_frequency_] -- add your slider handling code here..
        //[/UserSliderCode_arp_frequency_]
    }
    else if (sliderThatWasMoved == arp_gate_)
    {
        //[UserSliderCode_arp_gate_] -- add your slider handling code here..
        //[/UserSliderCode_arp_gate_]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

var SynthesisInterface::getState() {
    DynamicObject* state_object = new DynamicObject();
    std::map<std::string, Slider*>::iterator iter = slider_lookup_.begin();
    for (; iter != slider_lookup_.end(); ++iter) {
        state_object->setProperty(String(iter->first), iter->second->getValue());
    }
    return state_object;
}

void SynthesisInterface::writeState(var state) {
    DynamicObject* object_state = state.getDynamicObject();
    NamedValueSet properties = object_state->getProperties();
    int size = properties.size();
    for (int i = 0; i < size; ++i) {
        Identifier id = properties.getName(i);
        if (id.isValid()) {
            String name = id.toString();
            mopo::mopo_float value = properties.getValueAt(i);
            slider_lookup_[name.toStdString()]->setValue(value);
        }
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SynthesisInterface" componentName=""
                 parentClasses="public Component, public DragAndDropContainer"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff1f1f1f"/>
  <JUCERCOMP name="" id="83a23936a8f464b5" memberName="step_sequencer_" virtualName="GraphicalStepSequencer"
             explicitFocusOrder="0" pos="416 288 300 100" sourceFile="graphical_step_sequencer.cpp"
             constructorParams="16"/>
  <JUCERCOMP name="" id="b4880edb8b39ec9d" memberName="amplitude_envelope_"
             virtualName="GraphicalEnvelope" explicitFocusOrder="0" pos="416 392 300 100"
             sourceFile="graphical_envelope.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="87feb60c88df4fcc" memberName="filter_envelope_" virtualName="GraphicalEnvelope"
             explicitFocusOrder="0" pos="408 152 300 100" sourceFile="graphical_envelope.cpp"
             constructorParams=""/>
  <JUCERCOMP name="osc 1 wave display" id="55100715382ea344" memberName="osc_1_wave_display_"
             virtualName="WaveFormSelector" explicitFocusOrder="0" pos="40 8 240 100"
             sourceFile="wave_form_selector.cpp" constructorParams="128"/>
  <JUCERCOMP name="osc 2 wave display" id="c0c3e4a3ab2f045f" memberName="osc_2_wave_display_"
             virtualName="WaveFormSelector" explicitFocusOrder="0" pos="40 112 240 100"
             sourceFile="wave_form_selector.cpp" constructorParams="128"/>
  <SLIDER name="polyphony" id="952bde38857bdba7" memberName="polyphony_"
          virtualName="" explicitFocusOrder="0" pos="424 552 50 50" min="1"
          max="32" int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="portamento" id="9de85cc1c5f64eaa" memberName="portamento_"
          virtualName="" explicitFocusOrder="0" pos="424 608 50 50" min="0"
          max="0.2000000000000000111" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitch bend range" id="e53afc6d1a04c708" memberName="pitch_bend_range_"
          virtualName="" explicitFocusOrder="0" pos="576 552 50 50" min="0"
          max="48" int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="cross modulation" id="1d3e4b59d6e470fb" memberName="cross_modulation_"
          virtualName="" explicitFocusOrder="0" pos="320 16 50 50" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.5"/>
  <JUCERCOMP name="" id="e5ebb41c4c259ce1" memberName="filter_response_" virtualName="FilterResponse"
             explicitFocusOrder="0" pos="408 8 300 100" sourceFile="filter_response.cpp"
             constructorParams="128"/>
  <SLIDER name="legato" id="bae65942d016a0ea" memberName="legato_" virtualName=""
          explicitFocusOrder="0" pos="488 560 64 24" min="0" max="1" int="1"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="portamento type" id="909956998c46045e" memberName="portamento_type_"
          virtualName="" explicitFocusOrder="0" pos="488 616 64 24" min="0"
          max="2" int="1" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="osc mix" id="211f463b59b2454f" memberName="osc_mix_" virtualName=""
          explicitFocusOrder="0" pos="280 8 20 204" bkgcol="ff000000" textboxoutline="808080"
          min="0" max="1" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="osc 2 transpose" id="555c8ee21acbf804" memberName="osc_2_transpose_"
          virtualName="" explicitFocusOrder="0" pos="320 80 50 50" min="-48"
          max="48" int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="osc 2 tune" id="a8bc3bcffe7146f" memberName="osc_2_tune_"
          virtualName="" explicitFocusOrder="0" pos="320 144 50 50" min="-1"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="volume" id="7cc7edfbfc537ee7" memberName="volume_" virtualName=""
          explicitFocusOrder="0" pos="32 552 248 24" min="0" max="1" int="0"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="delay time" id="1c4c7f1a27492c1d" memberName="delay_time_"
          virtualName="" explicitFocusOrder="0" pos="96 496 50 50" min="0.010000000000000000208"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="2"/>
  <SLIDER name="delay feedback" id="c89eb62eea2ab491" memberName="delay_feedback_"
          virtualName="" explicitFocusOrder="0" pos="160 496 50 50" min="-1"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="delay dry wet" id="dbc9d35179b5bac7" memberName="delay_dry_wet_"
          virtualName="" explicitFocusOrder="0" pos="224 496 50 50" min="0"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocity track" id="113bdc65c4c0f18f" memberName="velocity_track_"
          virtualName="" explicitFocusOrder="0" pos="680 496 50 50" min="-1"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="amp attack" id="f6cda312a5619a33" memberName="amp_attack_"
          virtualName="" explicitFocusOrder="0" pos="424 496 50 50" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="amp decay" id="6de7c8b3a5a4826d" memberName="amp_decay_"
          virtualName="" explicitFocusOrder="0" pos="480 496 50 50" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="amp release" id="86b41ada65ec49c0" memberName="amp_release_"
          virtualName="" explicitFocusOrder="0" pos="592 496 50 50" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="amp sustain" id="3853f65a726f763" memberName="amp_sustain_"
          virtualName="" explicitFocusOrder="0" pos="536 496 50 50" min="0"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="fil attack" id="bc169bc84bd26782" memberName="fil_attack_"
          virtualName="" explicitFocusOrder="0" pos="416 256 32 32" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="fil decay" id="f5b3d1ec7fc18e1" memberName="fil_decay_"
          virtualName="" explicitFocusOrder="0" pos="456 256 32 32" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="fil release" id="c878127a7ada93f0" memberName="fil_release_"
          virtualName="" explicitFocusOrder="0" pos="536 256 32 32" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="fil sustain" id="5b25f915f3694f34" memberName="fil_sustain_"
          virtualName="" explicitFocusOrder="0" pos="496 256 32 32" min="0"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="resonance" id="6c1c82a2d59d4b6e" memberName="resonance_"
          virtualName="" explicitFocusOrder="0" pos="708 8 12 100" bkgcol="ff000000"
          textboxoutline="808080" min="0" max="1" int="0" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="filter type" id="30ae8dead7514514" memberName="filter_type_"
          virtualName="" explicitFocusOrder="0" pos="752 8 24 96" min="0"
          max="6" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="osc 1 waveform" id="ea97519d003b4224" memberName="osc_1_waveform_"
          virtualName="" explicitFocusOrder="0" pos="28 8 12 100" bkgcol="ff000000"
          textboxoutline="808080" min="0" max="11" int="1" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="0" textBoxHeight="0"
          skewFactor="1"/>
  <SLIDER name="osc 2 waveform" id="a38d2af584df969a" memberName="osc_2_waveform_"
          virtualName="" explicitFocusOrder="0" pos="28 112 12 100" bkgcol="ff000000"
          textboxoutline="0" min="0" max="11" int="1" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="cutoff" id="4ccde767164ea675" memberName="cutoff_" virtualName=""
          explicitFocusOrder="0" pos="408 108 300 12" bkgcol="ff000000"
          textboxoutline="808080" min="28" max="127" int="0" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="fil env depth" id="ac3a5967de6a1a92" memberName="fil_env_depth_"
          virtualName="" explicitFocusOrder="0" pos="624 256 32 32" min="-128"
          max="128" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keytrack" id="33bbd8b71aa721c1" memberName="keytrack_"
          virtualName="" explicitFocusOrder="0" pos="664 256 32 32" min="-1"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="osc feedback transpose" id="e747becfc7a4f3f7" memberName="osc_feedback_transpose_"
          virtualName="" explicitFocusOrder="0" pos="64 224 50 50" min="-24"
          max="24" int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="osc feedback amount" id="a94cee38c880759c" memberName="osc_feedback_amount_"
          virtualName="" explicitFocusOrder="0" pos="200 224 50 50" min="-1"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="osc feedback tune" id="90dc1d31f03abf4e" memberName="osc_feedback_tune_"
          virtualName="" explicitFocusOrder="0" pos="128 224 50 50" min="-1"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <JUCERCOMP name="amplitude env" id="49107c44dc2f49e9" memberName="amplitude_env_mod_source_"
             virtualName="" explicitFocusOrder="0" pos="728 424 24 24" sourceFile="modulation_source.cpp"
             constructorParams=""/>
  <JUCERCOMP name="step generator" id="539abd48959288ef" memberName="step_generator_mod_source_"
             virtualName="" explicitFocusOrder="0" pos="728 328 24 24" sourceFile="modulation_source.cpp"
             constructorParams=""/>
  <JUCERCOMP name="filter env" id="36ddd25be02a4fe1" memberName="filter_env_mod_source_"
             virtualName="" explicitFocusOrder="0" pos="720 184 24 24" sourceFile="modulation_source.cpp"
             constructorParams=""/>
  <JUCERCOMP name="cross mod" id="82ee43b8fbcceb78" memberName="cross_mod_destination_"
             virtualName="" explicitFocusOrder="0" pos="368 32 24 24" sourceFile="modulation_destination.cpp"
             constructorParams=""/>
  <JUCERCOMP name="pitch" id="146986590a708b08" memberName="pitch_mod_destination_"
             virtualName="" explicitFocusOrder="0" pos="368 88 24 24" sourceFile="modulation_destination.cpp"
             constructorParams=""/>
  <JUCERCOMP name="cutoff" id="9fcdd6545a5e9cd2" memberName="cutoff_mod_destination_"
             virtualName="" explicitFocusOrder="0" pos="720 8 24 24" sourceFile="modulation_destination.cpp"
             constructorParams=""/>
  <JUCERCOMP name="lfo 1 wave display" id="24d32b65108fb2a5" memberName="lfo_1_wave_display_"
             virtualName="WaveFormSelector" explicitFocusOrder="0" pos="40 280 240 100"
             sourceFile="wave_form_selector.cpp" constructorParams="128"/>
  <JUCERCOMP name="lfo 2 wave display" id="fec9561bdacebdbe" memberName="lfo_2_wave_display_"
             virtualName="WaveFormSelector" explicitFocusOrder="0" pos="40 384 240 100"
             sourceFile="wave_form_selector.cpp" constructorParams="128"/>
  <SLIDER name="lfo 1 waveform" id="4ed06bb2c6901afe" memberName="lfo_1_waveform_"
          virtualName="" explicitFocusOrder="0" pos="28 280 12 100" bkgcol="ff000000"
          textboxoutline="808080" min="0" max="11" int="1" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="0" textBoxHeight="0"
          skewFactor="1"/>
  <SLIDER name="lfo 2 waveform" id="72004168ec47b7e7" memberName="lfo_2_waveform_"
          virtualName="" explicitFocusOrder="0" pos="28 384 12 100" bkgcol="ff000000"
          textboxoutline="0" min="0" max="11" int="1" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="0" textBoxHeight="0"
          skewFactor="1"/>
  <JUCERCOMP name="lfo 1" id="9571e0e9ba0fa53a" memberName="lfo_1_mod_source_"
             virtualName="" explicitFocusOrder="0" pos="288 320 24 24" sourceFile="modulation_source.cpp"
             constructorParams=""/>
  <JUCERCOMP name="lfo 2" id="57b28b867a25f366" memberName="lfo_2_mod_source_"
             virtualName="" explicitFocusOrder="0" pos="288 424 24 24" sourceFile="modulation_source.cpp"
             constructorParams=""/>
  <JUCERCOMP name="resonance" id="5bac7839db359a73" memberName="resonance_mod_destination_"
             virtualName="" explicitFocusOrder="0" pos="680 120 24 24" sourceFile="modulation_destination.cpp"
             constructorParams=""/>
  <SLIDER name="arp frequency" id="90264eb571112e1b" memberName="arp_frequency_"
          virtualName="" explicitFocusOrder="0" pos="176 576 50 50" min="1"
          max="20" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="arp gate" id="e8f61b752c6d561e" memberName="arp_gate_"
          virtualName="" explicitFocusOrder="0" pos="88 576 50 50" min="0"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]