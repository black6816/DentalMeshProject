#ifndef SW_MAINWINDOW_H
#define SW_MAINWINDOW_H

//
//  BoundingBox.h
//  Reconstructor
//
//  Created by sway on 6/13/15.
//  Copyright (c) 2015 None. All rights reserved.
//


#include "GLViewer.h"
#include "ui_mainwindow.h"
#include "include/Mesh.h"

#include <QMainWindow>
#include "qlayout.h"
#include "qcursor.h"
#include "qevent.h"
#include <QWidget>
#include "qnamespace.h"
#include <QFrame>
#include <QSlider>
#include <QCheckBox>
#include <QAction>
#include <QActionGroup>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QListWidget>

#include"basicType.h"
#include "ToothSegmentation.h"
#include"BooleanOperation.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem; //
//class QActionGroup;
//class QToolBar;
//class QMenu;
//class QSlider;
//class QFrame;
//class QCheckBox;
class QPushButton;
class QTimer;
class QKeyEvent;
class GLViewer;

namespace SW
{
class MainWindow: public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow(); // to be implemented


    void setCurrentProcessMode(ProcessMode mode){
        mCurrentProcessMode = mode;
    }

    ProcessMode getCurrentProcessMode() const{
        return mCurrentProcessMode;
    }

protected:

    virtual void keyPressEvent(QKeyEvent *);
    Mesh boolOperation(BooleanOperation type);


protected slots:
    void doActionOpen();
    void doActionCloseAll();

    void doActionToolthSegmentation(bool checked);
    void doActionBooleanOperation(bool checked);
    void doActionUnion();
    void doActionIntersection();
    void doActionDifference();

    // Laplacian transformation
    void doActionLaplacianDeformation(bool checked);
    void doActionSelectPoints(bool checked);
    void doActionDo_Deformation(bool checked);
    void doAcationReset();

    void doActionToothSegmentationAutomaticCuttingOfGingivaFlipCuttingPlane();
    void doActionToothSegmentationAutomaticCuttingOfGingivaMoveCuttingPlaneUp();
    void doActionToothSegmentationAutomaticCuttingOfGingivaMoveCuttingPlaneDown();

#ifdef  EARLER_VERSION
    void doActionToothSegmentationIdentifyPotentialToothBoundary();
    void doActionToothSegmentationAutomaticCuttingOfGingiva();
    void doActionToothSegmentationBoundarySkeletonExtraction();
    void doActionToothSegmentationFindCuttingPoints();
    void doActionToothSegmentationRefineToothBoundary();
#endif
    void doActionToothSegmentationManuallyShowVertexProperties(bool checked);
    void doActionToothSegmentationManuallyAddBoundaryVertex(bool checked);
    void doActionToothSegmentationManuallyDeleteBoundaryVertex(bool checked);
    void doActionToothSegmentationManuallyDeleteErrorToothRegion(bool checked);
    void doActionToothSegmentationManuallyDeleteErrorContourSection(bool checked);
    void doActionToothSegmentationEnableManualOperation(bool enable);
    void doActionToothSegmentationProgramControl();

public slots:
    void saveToothSegmentationHistory();
    void changeToolbarButtonStatusAccordingToToothSegmentationProgramSchedule(int programSchedule);

private:
    void setAllManualOperationActionUnChecked();
    void setOtherManualOperationActionUnChecked(QAction *checkedAction);

signals:

private:

    ProcessMode mCurrentProcessMode;
    Mesh mOriginalMeshForSegmentation;
    Mesh m_OrignalMeshForBooleanOpearion[2];

    ToothSegmentation *mToothSegmentation;
    QVector<QAction *> mToothSegmentationManualOperationActions;
    QVector<ToothSegmentation> mToothSegmentationHistory;
    int mToothSegmentationUsingIndexInHistory;

};

}



#endif // SW_MAINWINDOW_H


