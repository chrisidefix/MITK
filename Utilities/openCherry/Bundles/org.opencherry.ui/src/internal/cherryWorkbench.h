/*=========================================================================

Program:   openCherry Platform
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef CHERRYWORKBENCH_H_
#define CHERRYWORKBENCH_H_

#include "../cherryIViewPart.h"
#include "../cherryIWorkbench.h"
#include "../cherryWorkbenchWindow.h"
#include "../cherryIWorkbenchPage.h"
#include "../cherryIWorkbenchPartReference.h"

#include "../cherryPartPane.h"
#include "cherryEditorAreaHelper.h"
#include "cherryWindowManager.h"
#include "cherryWorkbenchConfigurer.h"
#include "../application/cherryWorkbenchAdvisor.h"

#include "cherryServiceLocator.h"

#include <Poco/Exception.h>

namespace cherry {

class ViewRegistry;
class EditorRegistry;
class WorkbenchWindowConfigurer;

/**
 * \ingroup org_opencherry_ui
 *
 * The workbench class represents the top of the openCherry user interface. Its
 * primary responsability is the management of workbench windows, dialogs,
 * wizards, and other workbench-related windows.
 * <p>
 * Note that any code that is run during the creation of a workbench instance
 * should not required access to the display.
 */
class CHERRY_UI Workbench : public IWorkbench
{

public:

  cherryObjectMacro(Workbench);

  /**
   * Creates the workbench and associates it with the the given display and
   * workbench advisor, and runs the workbench UI. This entails processing and
   * dispatching events until the workbench is closed or restarted.
   * <p>
   * This method is intended to be called by <code>PlatformUI</code>. Fails
   * if the workbench UI has already been created.
   * </p>
   *
   * @param advisor
   *            the application-specific advisor that configures and
   *            specializes the workbench
   * @return return code {@link PlatformUI#RETURN_OK RETURN_OK}for normal
   *         exit; {@link PlatformUI#RETURN_RESTART RETURN_RESTART}if the
   *         workbench was terminated with a call to
   *         {@link IWorkbench#restart IWorkbench.restart}; other values
   *         reserved for future use
   */
  static int CreateAndRunWorkbench(WorkbenchAdvisor* advisor);

  /**
   * Returns the one and only instance of the workbench, if there is one.
   *
   * @return the workbench, or <code>null</code> if the workbench has not
   *         been created, or has been created and already completed
   */
  static Workbench* GetInstance();

  virtual ~Workbench();

  /*
   * (non-Javadoc)
   *
   * @see org.opencherry.ui.services.IServiceLocator#getService(java.lang.Object)
   */
  Object::Pointer GetService(const std::string& key);

  /*
   * (non-Javadoc)
   *
   * @see org.opencherry.ui.services.IServiceLocator#hasService(java.lang.Object)
   */
  bool HasService(const std::string& key) const;

  /*
   * Method declared on IWorkbench.
   */
  bool Close();

  /*
   *  Method declared on IWorkbench.
   */
  void AddWorkbenchListener(IWorkbenchListener::Pointer listener);

  /*
   * Method declared on IWorkbench.
   */
  void RemoveWorkbenchListener(IWorkbenchListener::Pointer listener);

  /*
   * Method declared on IWorkbench.
   */
  IWorkbenchListener::Events& GetWorkbenchEvents();

  /*
   * Method declared on IWorkbench.
   */
  void AddWindowListener(IWindowListener::Pointer l);

  /*
   * Method declared on IWorkbench.
   */
  void RemoveWindowListener(IWindowListener::Pointer l);

  /*
   * Method declared on IWorkbench.
   */
  IWindowListener::Events& GetWindowEvents();

  IWorkbenchWindow::Pointer GetActiveWorkbenchWindow();

  IViewRegistry* GetViewRegistry();
  IEditorRegistry* GetEditorRegistry();
  IPerspectiveRegistry* GetPerspectiveRegistry();

  int GetWorkbenchWindowCount();
  std::vector<IWorkbenchWindow::Pointer> GetWorkbenchWindows();
  IWorkbenchWindow::Pointer OpenWorkbenchWindow(const std::string& perspectiveId,
        IAdaptable* input);
  IWorkbenchWindow::Pointer OpenWorkbenchWindow(IAdaptable* input);

  IWorkbenchPage::Pointer ShowPerspective(const std::string& perspectiveId,
      IWorkbenchWindow::Pointer window);

  IWorkbenchPage::Pointer ShowPerspective(const std::string& perspectiveId,
        IWorkbenchWindow::Pointer window, IAdaptable* input);

  bool SaveAllEditors(bool confirm);

  /**
   * Returns <code>true</code> if the workbench is running,
   * <code>false</code> if it has been terminated.
   *
   * @return <code>true</code> if the workbench is running,
   *         <code>false</code> if it has been terminated.
   */
  bool IsRunning();

  /**
   * Returns true if the Workbench is in the process of starting.
   *
   * @return <code>true</code> if the Workbench is starting, but not yet
   *         running the event loop.
   */
  bool IsStarting();

  bool IsClosing();

  /**
   * Returns the default perspective id, which may be <code>null</code>.
   *
   * @return the default perspective id, or <code>null</code>
   */
  std::string GetDefaultPerspectiveId();

  /**
   * Returns the default workbench window page input.
   *
   * @return the default window page input or <code>null</code> if none
   */
  IAdaptable* GetDefaultPageInput();

  /**
   * Return the presentation ID specified by the preference or the default ID
   * if undefined.
   *
   * @return the presentation ID
   * @see IWorkbenchPreferenceConstants#PRESENTATION_FACTORY_ID
   */
  std::string GetPresentationId();

  /**
   * <p>
   * Indicates the start of a large update within the workbench. This is used
   * to disable CPU-intensive, change-sensitive services that were temporarily
   * disabled in the midst of large changes. This method should always be
   * called in tandem with <code>largeUpdateEnd</code>, and the event loop
   * should not be allowed to spin before that method is called.
   * </p>
   * <p>
   * Important: always use with <code>largeUpdateEnd</code>!
   * </p>
   */
  void LargeUpdateStart();

  /**
   * <p>
   * Indicates the end of a large update within the workbench. This is used to
   * re-enable services that were temporarily disabled in the midst of large
   * changes. This method should always be called in tandem with
   * <code>largeUpdateStart</code>, and the event loop should not be
   * allowed to spin before this method is called.
   * </p>
   * <p>
   * Important: always protect this call by using <code>finally</code>!
   * </p>
   */
  void LargeUpdateEnd();


protected:

  friend class PlatformUI;
  friend class WorkbenchConfigurer;
  friend class WorkbenchWindowConfigurer;
  friend class WorkbenchWindow;
  friend class WorkbenchWindow::ShellActivationListener;

  int RunUI();

  void OpenFirstTimeWindow();
  IWorkbenchWindow::Pointer RestoreWorkbenchWindow(IMemento::Pointer memento);

  bool Init();

  /**
   * Closes the workbench, returning the given return code from the run
   * method. If forced, the workbench is closed no matter what.
   *
   * @param returnCode
   *            {@link PlatformUI#RETURN_OK RETURN_OK}for normal exit;
   *            {@link PlatformUI#RETURN_RESTART RETURN_RESTART}if the
   *            workbench was terminated with a call to
   *            {@link IWorkbench#restart IWorkbench.restart};
   *            {@link PlatformUI#RETURN_EMERGENCY_CLOSE} for an emergency
   *            shutdown
   *            {@link PlatformUI#RETURN_UNSTARTABLE RETURN_UNSTARTABLE}if
   *            the workbench could not be started; other values reserved for
   *            future use
   *
   * @param force
   *            true to force the workbench close, and false for a "soft"
   *            close that can be canceled
   * @return true if the close was successful, and false if the close was
   *         canceled
   */
  /* package */
  bool Close(int returnCode, bool force);

  /**
   * Returns the unique object that applications use to configure the
   * workbench.
   * <p>
   * IMPORTANT This method is declared protected to prevent regular
   * plug-ins from downcasting IWorkbench to Workbench and getting hold of the
   * workbench configurer that would allow them to tamper with the workbench.
   * The workbench configurer is available only to the application.
   * </p>
   */
  WorkbenchConfigurer::Pointer GetWorkbenchConfigurer();

  /**
   * Returns the workbench advisor that created this workbench.
   * <p>
   * IMPORTANT This method is declared protected to prevent regular
   * plug-ins from downcasting IWorkbench to Workbench and getting hold of the
   * workbench advisor that would allow them to tamper with the workbench. The
   * workbench advisor is internal to the application.
   * </p>
   */
  WorkbenchAdvisor* GetAdvisor();

  /*
   * Returns the workbench window which was last known being the active one,
   * or <code> null </code> .
   */
  SmartPointer<WorkbenchWindow> GetActivatedWindow();

  /*
   * Sets the workbench window which was last known being the active one, or
   * <code> null </code> .
   */
  void SetActivatedWindow(SmartPointer<WorkbenchWindow> window);

  /**
   * Fire workbench preShutdown event, stopping at the first one to veto
   *
   * @param forced
   *            flag indicating whether the shutdown is being forced
   * @return <code>true</code> to allow the workbench to proceed with
   *         shutdown, <code>false</code> to veto a non-forced shutdown
   * @since 3.2
   */
  bool FirePreShutdown(bool forced);

  /**
   * Fire workbench postShutdown event.
   *
   * @since 3.2
   */
  void FirePostShutdown();

  /**
   * Fire window opened event.
   *
   * @param window
   *            The window which just opened; should not be <code>null</code>.
   */
  void FireWindowOpened(IWorkbenchWindow::Pointer window);

  /**
   * Fire window closed event.
   *
   * @param window
   *            The window which just closed; should not be <code>null</code>.
   */
  void FireWindowClosed(IWorkbenchWindow::Pointer window);

  /**
   * Fire window activated event.
   *
   * @param window
   *            The window which was just activated; should not be
   *            <code>null</code>.
   */
  void FireWindowActivated(IWorkbenchWindow::Pointer window);

  /**
   * Fire window deactivated event.
   *
   * @param window
   *            The window which was just deactivated; should not be
   *            <code>null</code>.
   */
  void FireWindowDeactivated(IWorkbenchWindow::Pointer window);


private:

  /**
   * Holds onto the only instance of Workbench.
   */
  static Workbench* instance;

  IWorkbenchListener::Events workbenchEvents;
  IWindowListener::Events windowEvents;

  WorkbenchAdvisor* advisor;
  WorkbenchConfigurer::Pointer workbenchConfigurer;

  /**
   * The service locator maintained by the workbench. These services are
   * initialized during workbench during the <code>init</code> method.
   */
  ServiceLocator::Pointer serviceLocator;

  struct ServiceLocatorOwner : public IDisposable
  {
    ServiceLocatorOwner(Workbench* workbench);

    void Dispose();

  private:
    Workbench* workbench;
  };

  friend struct ServiceLocatorOwner;

  IDisposable::Pointer serviceLocatorOwner;

  /**
   * A count of how many large updates are going on. This tracks nesting of
   * requests to disable services during a large update -- similar to the
   * <code>setRedraw</code> functionality on <code>Control</code>. When
   * this value becomes greater than zero, services are disabled. When this
   * value becomes zero, services are enabled. Please see
   * <code>largeUpdateStart()</code> and <code>largeUpdateEnd()</code>.
   */
  int largeUpdates;

  WindowManager windowManager;
  SmartPointer<WorkbenchWindow> activatedWindow;

  bool isStarting;
  bool isClosing;

  int returnCode;

  std::string factoryID;

  /**
   * Creates a new workbench.
   *
   * @param advisor
   *            the application-specific advisor that configures and
   *            specializes this workbench instance
   */
  Workbench(WorkbenchAdvisor* advisor);

  /*
   * Creates a new workbench window.
   *
   * @return the new workbench window
   */
  SmartPointer<WorkbenchWindow> NewWorkbenchWindow();

  /*
   * Returns the number for a new window. This will be the first number > 0
   * which is not used to identify another window in the workbench.
   */
  int GetNewWindowNumber();

  /**
   * Initializes all of the default services for the workbench. For
   * initializing the command-based services, this also parses the registry
   * and hooks up all the required listeners.
   */
  void InitializeDefaultServices();

  /**
   * Closes the workbench. Assumes that the busy cursor is active.
   *
   * @param force
   *            true if the close is mandatory, and false if the close is
   *            allowed to fail
   * @return true if the close succeeded, and false otherwise
   */
  bool BusyClose(bool force);

  /*
   * Shuts down the application.
   */
  void Shutdown();

  /**
   * Opens a new workbench window and page with a specific perspective.
   *
   * Assumes that busy cursor is active.
   */
  IWorkbenchWindow::Pointer BusyOpenWorkbenchWindow(const std::string& perspID,
      IAdaptable* input);
};

} // namespace cherry

#endif /*CHERRYWORKBENCH_H_*/
