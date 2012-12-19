// recreated by inference

#ifndef _EM_BE_FILE_INPUT_DESCRIPTOR_H
#define _EM_BE_FILE_INPUT_DESCRIPTOR_H

class EMBeFileInputDescriptor : public EMFileInputDescriptor
{
public:
							EMBeFileInputDescriptor(string, EMMediaType);
	virtual					~EMBeFileInputDescriptor();

	virtual EMMediaFormat* 	GetFormat();

	virtual bool 			InitCheckE();;

	virtual bool 			ReadFrames(EMMediaDataBuffer**primaryBuffer,
								EMMediaDataBuffer** secondaryBuffer,
								int64 mediaFramePosition,
								int64 offsetFrames,
								int64 & numRead, bool seeking = false);

	virtual bool 			SeekAndDisplay(int64 frame) = 0;

	virtual bool 			SeekTo(int64 frame);


	virtual bool			Open();
	virtual bool 			Close();



};

#endif

