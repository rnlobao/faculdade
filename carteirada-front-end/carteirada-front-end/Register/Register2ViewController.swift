//
//  Register2ViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import UIKit

protocol ServiceDelegate {
    func dataSucess()
    func dataFail(error: Error)
    func showLoad()
    func removeLoad()
}

class Register2ViewController: UIViewController {

    @IBOutlet weak var registerButtonEdit: UIButton!
    @IBOutlet weak var emailTF: UITextField!
    @IBOutlet weak var userTF: UITextField!
    @IBOutlet weak var pwTF: UITextField!
    @IBOutlet weak var confirmPWTF: UITextField!
    
    private var viewModel: Register2ViewModel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        viewModel = Register2ViewModel(delegate: self)
        setupButton()
        setupPWTextFields()
    }
    
    private func setupPWTextFields() {
        pwTF.isSecureTextEntry = true
        confirmPWTF.isSecureTextEntry = true
    }
    
    
    
    @IBAction func sendUser(_ sender: Any) {
//        if viewModel.canWePostIt(user: String(userTF.text ?? ""), email: emailTF.text ?? "", senha: pwTF.text ?? "") == true  {
//            viewModel.postDataUser(login: userTF.text ?? "", email: emailTF.text ?? "", password: pwTF.text ?? "")
//        } else {
//            let alert = UIAlertController(title: "aaa", message: "aaa", preferredStyle: .alert)
//                        alert.addAction(UIAlertAction(title: "aaa", style: .destructive, handler: nil))
//            self.present(alert, animated: true)
//        }
        viewModel.postDataUser(login: userTF.text ?? "", email: emailTF.text ?? "", password: pwTF.text ?? "")
    }
    
    func setupButton() {
        registerButtonEdit.layer.cornerRadius = 20
        registerButtonEdit.layer.shadowColor = UIColor.black.cgColor
        registerButtonEdit.layer.shadowOffset = CGSize(width: 0.0, height: 4.0)
        registerButtonEdit.layer.shadowRadius = 4.0
        registerButtonEdit.layer.shadowOpacity = 0.5
        registerButtonEdit.layer.masksToBounds = false
    }

}

extension Register2ViewController: ServiceDelegate {
    func dataSucess() {
            let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
                self.dismiss(animated: true, completion: nil)
                
            }))
            self.present(alert, animated: true)
        }
        
        func dataFail(error: Error) {
            let alert = UIAlertController(title: "Erro", message: error.localizedDescription, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Ok", style: .destructive, handler: nil))
            self.present(alert, animated: true)
        }
        
        func showLoad() {
            showSpinner(onView: view)
        }
        
        func removeLoad() {
            removeSpinner()
        }
}
